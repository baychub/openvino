// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

/**
 * @brief Defines fused names attribute
 * @file fused_names_attribute.hpp
 */

#include <assert.h>
#include <functional>
#include <memory>
#include <string>
#include <set>

#include <ngraph/node.hpp>
#include <ngraph/variant.hpp>
#include <transformations_visibility.hpp>


namespace ngraph {

/**
 * @ingroup ie_runtime_attr_api
 * @brief Dequantization class represents runtime info attribute that indicates
 * whether the operation is dequantization
 */
class TRANSFORMATIONS_API DequantizationAttr {
private:
    std::string dequantization_attribute;

public:
    /**
     * A default constructor
     */
    DequantizationAttr() = default;

    /**
     * @brief      Constructs a new object consisting of a single name     *
     * @param[in]  name  The name
     */
    explicit DequantizationAttr(const std::string& name) : dequantization_attribute(name) {}

    /**
     * @brief return string with dequantization value
     */
    std::string getDequantizationAttr() const;
};
/**
 * @ingroup ie_runtime_attr_api
 * @brief getDequantization return string with dequantization value
 * @param[in] node The node will be used to get Dequantization attribute
 */
TRANSFORMATIONS_API std::string getDequantization(const std::shared_ptr<ngraph::Node>& node);

}  // namespace ngraph

namespace ov {

extern template class TRANSFORMATIONS_API VariantImpl<ngraph::DequantizationAttr>;

template<>
class TRANSFORMATIONS_API VariantWrapper<ngraph::DequantizationAttr> : public VariantImpl<ngraph::DequantizationAttr> {
public:
    static constexpr VariantTypeInfo type_info{"DEQUANTIZATION", 0};

    const VariantTypeInfo &get_type_info() const override {
        return type_info;
    }

    VariantWrapper(const value_type &value) : VariantImpl<value_type>(value) {}

    std::shared_ptr<ngraph::Variant> merge(const ngraph::NodeVector & nodes) override;

    std::shared_ptr<ngraph::Variant> init(const std::shared_ptr<ngraph::Node> & node) override;
};

}  // namespace ov
