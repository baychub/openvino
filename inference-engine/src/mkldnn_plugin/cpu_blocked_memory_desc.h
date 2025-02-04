// Copyright (C) 2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "cpu_memory_desc.h"

namespace MKLDNNPlugin {

class MKLDNNMemoryDesc;

class BlockedMemoryDesc : public MemoryDesc {
public:
    BlockedMemoryDesc(InferenceEngine::Precision prc, const std::vector<size_t>& dims);

    BlockedMemoryDesc(InferenceEngine::Precision prc, const std::vector<size_t>& dims, const std::vector<size_t>& blockedDims,
                      const std::vector<size_t>& order, size_t offsetPadding = 0, const std::vector<size_t>& offsetPaddingToData = {},
                      const std::vector<size_t>& strides = {});

    MemoryDescPtr clone() const override {
        return MKLDNNPlugin::make_unique<BlockedMemoryDesc>(*this);
    }

    bool isDefined() const override;

    bool isCompatible(const MemoryDesc& rhs) const override;

    bool isCompatible(const BlockedMemoryDesc& rhs) const;

    bool isCompatible(const MKLDNNMemoryDesc& rhs) const;

    InferenceEngine::Precision getPrecision() const override {
        return precision;
    }

    void setPrecision(InferenceEngine::Precision prc) override {
        precision = std::move(prc);
    }

    const std::vector<size_t>& getBlockDims() const {
        return blockedDims;
    }

    /**
     * @brief Returns the vector of order
     *
     * @return order
     */
    const std::vector<size_t>& getOrder() const {
        return order;
    }

    /**
     * @brief Returns the per-dimension offset vector
     *
     * @return offsets
     */
    const std::vector<size_t>& getOffsetPaddingToData() const {
        return offsetPaddingToData;
    }
    /**
     * @brief Returns the offset to the current memory block
     *
     * @return offset
     */
    size_t getOffsetPadding() const {
        return offsetPadding;
    }

    /**
     * @brief Returns strides for each dimension
     *
     * @return strides
     */
    const std::vector<size_t>& getStrides() const {
        return strides;
    }

    bool hasLayoutType(LayoutType layoutType) const override;

    std::string serializeFormat() const override;

private:
    size_t getElementOffset(size_t elemNumber) const override;
    size_t getMemSizeImp() const override;
    size_t getOffset(const InferenceEngine::SizeVector& v) const;
    bool isPlainFormat() const;
    bool isBlockedCFormat(size_t blk_size) const;
    bool isTailCFormat() const;

private:
    InferenceEngine::Precision precision;
    std::vector<size_t> blockedDims;
    std::vector<size_t> strides;
    std::vector<size_t> order;
    std::vector<size_t> offsetPaddingToData;
    size_t offsetPadding;
};
} // namespace MKLDNNPlugin
