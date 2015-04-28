#pragma once
#ifndef _CL_SPARSE_2x_H_
#define _CL_SPARSE_2x_H_

#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

// Data types used to pass OpenCL objects into the clSPARSE library
// These are plain PoD containers; no methods defined
// Users are responsible for creating and destroying the OpenCL objects
// Helper functions may be provided to assist users in creating and 
// destroying these objects
typedef struct clsparseScalar_
{
    // OpenCL state
    void* value;
} clsparseScalar;

typedef struct clsparseVector_
{
    // Matrix meta
    cl_int n;

    // OpenCL state
    void* values;
} clsparseVector;

typedef struct clsparseCsrMatrix_
{
    // Matrix meta
    cl_int m;
    cl_int n;
    cl_int nnz;

    // OpenCL state
    void* values;
    void* colIndices;
    void* rowOffsets;
    void* rowBlocks;      // It is possible that this pointer may be NULL

    size_t rowBlockSize;
} clsparseCsrMatrix;

typedef struct clsparseCooMatrix_
{
    // Matrix meta
    cl_int m;
    cl_int n;
    cl_int nnz;

    // OpenCL state
    void* values;
    void* colIndices;
    void* rowIndices;
} clsparseCooMatrix;

typedef struct clsparseDenseMatrix_
{
    cl_int m;
    cl_int n;

    void* values;

} clsparseDenseMatrix;

#endif
