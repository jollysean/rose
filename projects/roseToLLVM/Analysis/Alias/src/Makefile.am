include $(top_srcdir)/config/Makefile.for.ROSE.includes.and.libs

if ROSE_USE_LLVM

AM_CPPFLAGS = $(ROSE_INCLUDES) \
		   $(ROSE_LLVM_INCLUDES) \
		   $(ROSE_BOOST_INCLUDES) \
		   -I$(top_srcdir)/projects/roseToLLVM/src/rosetollvm/include \
		   -I$(top_srcdir)/projects/roseToLLVM/Analysis/Alias/include 

#include_HEADERS = AliasAnalysisModule.h

bin_PROGRAMS = rose2llvmAA

rose2llvmAA_SOURCES  = AliasSetHandler.cpp \
					   AliasAnalysisModule.cpp \
					   AliasAnalysisGatherer.cpp \
					   AnnotateAST.cpp \
					   AliasSetContainer.cpp \
					   AssociateRoseAST.cpp \
					   QueryAST.cpp \
					   AliasAnalysis.cpp 

												   

rose2llvmAA_CPPFLAGS = -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -Wno-deprecated -g

rose2llvmAA_LDADD = $(top_builddir)/projects/roseToLLVM/src/rosetollvm/librosetollvm.la

endif
