// Author: Markus Schordan, 2013.

#ifndef CPASTATTRIBUTEINTERFACE_H
#define CPASTATTRIBUTEINTERFACE_H

#include "Labeler.h"
#include "VariableIdMapping.h"
#include "DFAstAttribute.h"

/*! 
  * \author Markus Schordan
  * \date 2013.
 */
class CPAstAttributeInterface : public DFAstAttribute {
 public:
  typedef ssize_t ConstantInteger;
  typedef pair<VariableId,ConstantInteger> CPPair;
  typedef set<CPPair> CPPairSet;
  typedef CPPairSet::iterator iterator;
  //virtual VariableIdSet allVariableIds()=0;
  virtual bool isConstantInteger(VariableId varId)=0;
  virtual ConstantInteger getConstantInteger(VariableId varId)=0;
  //virtual iterator begin()=0;
  //virtual iterator end()=0;
  virtual ~CPAstAttributeInterface();
};

#endif
