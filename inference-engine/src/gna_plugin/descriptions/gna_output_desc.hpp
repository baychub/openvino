// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <vector>

#include "backend/dnn_types.h"

namespace GNAPluginNS {
struct OutputDesc {
    uint8_t precision;
    double scale_factor = 1.0;
    uint32_t num_bytes_per_element = 0;
    uint32_t num_elements = 0;
    std::vector<void *> ptrs;  // ptr per each infer request
    intel_dnn_orientation_t orientation = kDnnUnknownOrientation;
};
}  // namespace GNAPluginNS
