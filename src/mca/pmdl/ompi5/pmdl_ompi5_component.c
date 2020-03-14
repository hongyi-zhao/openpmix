/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2004-2008 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2015      Los Alamos National Security, LLC. All rights
 *                         reserved.
 * Copyright (c) 2016-2020 Intel, Inc.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 *
 */

#include <src/include/pmix_config.h>
#include "pmix_common.h"

#include "src/mca/pmdl/pmdl.h"
#include "pmdl_ompi5.h"

static pmix_status_t component_query(pmix_mca_base_module_t **module, int *priority);

/*
 * Instantiate the public struct with all of our public information
 * and pointers to our public functions in it
 */
pmix_pmdl_base_component_t mca_pmdl_ompi5_component = {
    .base = {
        PMIX_PMDL_BASE_VERSION_1_0_0,

        /* Component name and version */
        .pmix_mca_component_name = "ompi5",
        PMIX_MCA_BASE_MAKE_VERSION(component,
                                   PMIX_MAJOR_VERSION,
                                   PMIX_MINOR_VERSION,
                                   PMIX_RELEASE_VERSION),

        /* Component open and close functions */
        .pmix_mca_query_component = component_query,
    },
    .data = {
        /* The component is checkpoint ready */
        PMIX_MCA_BASE_METADATA_PARAM_CHECKPOINT
    }
};

static pmix_status_t component_query(pmix_mca_base_module_t **module, int *priority)
{
    *priority = 55;
    *module = (pmix_mca_base_module_t *)&pmix_pmdl_ompi5_module;
    return PMIX_SUCCESS;
}
