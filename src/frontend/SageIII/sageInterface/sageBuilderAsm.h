#ifndef ROSE_SageBuilderAsm_H
#define ROSE_SageBuilderAsm_H

namespace SageBuilderAsm {

// Generic data types
SgAsmIntegerType* buildTypeU1();                        /**< 1-bit unsigned (Boolean) */
SgAsmIntegerType* buildTypeU8();                        /**< 8-bit unsigned */
SgAsmIntegerType* buildTypeU16le();                     /**< 16-bit unsigned little-endian */
SgAsmIntegerType* buildTypeU16be();                     /**< 16-bit unsigned big-endian */
SgAsmIntegerType* buildTypeU32le();                     /**< 32-bit unsigned little-endian */
SgAsmIntegerType* buildTypeU32be();                     /**< 32-bit unsigned big-endian */
SgAsmIntegerType* buildTypeU64le();                     /**< 64-bit unsigned little-endian */
SgAsmIntegerType* buildTypeU64be();                     /**< 64-bit unsigned big-endian */
SgAsmIntegerType* buildTypeI8();                        /**< 8-bit signed */
SgAsmIntegerType* buildTypeI16le();                     /**< 16-bit signed little-endian */
SgAsmIntegerType* buildTypeI16be();                     /**< 16-bit signed big-endian */
SgAsmIntegerType* buildTypeI32le();                     /**< 32-bit signed little-endian */
SgAsmIntegerType* buildTypeI32be();                     /**< 32-bit signed big-endian */
SgAsmIntegerType* buildTypeI64le();                     /**< 64-bit signed little-endian */
SgAsmIntegerType* buildTypeI64be();                     /**< 64-bit signed big-endian */
SgAsmFloatType* buildIeee754Binary32le();               /**< 32-bit IEEE-754 little-endian floating-point */
SgAsmFloatType* buildIeee754Binary32be();               /**< 32-bit IEEE-754 big-endian floating-point */
SgAsmFloatType* buildIeee754Binary64le();               /**< 64-bit IEEE-754 little-endian floating-point */
SgAsmFloatType* buildIeee754Binary64be();               /**< 64-bit IEEE-754 big-endian floating-point */
SgAsmFloatType* buildIeee754Binary80le();               /**< 80-bit IEEE-754 little-endian floating-point (as in x86) */
SgAsmVectorType* buildTypeVector(size_t, SgAsmType*);   /**< Fixed-size, packed array */

// Architecture-specific data types
SgAsmIntegerType *buildTypeX86Byte();                   /**< 8-bit unsigned little-endian */
SgAsmIntegerType *buildTypeX86Word();                   /**< 16-bit unsigned little-endian */
SgAsmIntegerType *buildTypeX86DoubleWord();             /**< 32-bit unsigned little-endian */
SgAsmIntegerType *buildTypeX86QuadWord();               /**< 64-bit unsigned little-endian */
SgAsmFloatType *buildTypeX86Float32();                  /**< 32-bit IEEE-754 little-endian floating-point */
SgAsmFloatType *buildTypeX86Float64();                  /**< 64-bit IEEE-754 little-endian floating-point */
SgAsmFloatType *buildTypeX86Float80();                  /**< 80-bit IEEE-754 little-endian floating-point */
SgAsmVectorType *buildTypeX86DoubleQuadWord();          /**< Vector of two 64-bit unsigned little-endian elements */
SgAsmFloatType *buildTypeM68kFloat96();                 /**< Motorola M68k 96-bit float (16-bits are always zero) */

// x86-specific data types (deprecated [Robb P. Matzke 2014-07-21]; use the functions with X86 in their names)
SgAsmIntegerType* buildAsmTypeByte() ROSE_DEPRECATED;
SgAsmIntegerType* buildAsmTypeWord() ROSE_DEPRECATED;
SgAsmIntegerType* buildAsmTypeDoubleWord() ROSE_DEPRECATED;
SgAsmIntegerType* buildAsmTypeQuadWord() ROSE_DEPRECATED;
SgAsmFloatType*   buildAsmTypeSingleFloat() ROSE_DEPRECATED;
SgAsmFloatType*   buildAsmTypeDoubleFloat() ROSE_DEPRECATED;
SgAsmFloatType*   buildAsmType128bitFloat() ROSE_DEPRECATED;
SgAsmFloatType*   buildAsmType80bitFloat() ROSE_DEPRECATED;
SgAsmVectorType*  buildAsmTypeDoubleQuadWord() ROSE_DEPRECATED;

// Build instruction; some deprecated because of incorrect capitalization [Robb P. Matzke 2014-07-21]
SgAsmx86Instruction* buildx86Instruction(X86InstructionKind) ROSE_DEPRECATED;
SgAsmx86Instruction* buildX86Instruction(X86InstructionKind);
SgAsmx86Instruction* buildx86Instruction(X86InstructionKind, SgAsmExpression *operand) ROSE_DEPRECATED;
SgAsmx86Instruction* buildX86Instruction(X86InstructionKind, SgAsmExpression *operand);
SgAsmx86Instruction* buildx86Instruction(X86InstructionKind, SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmx86Instruction* buildX86Instruction(X86InstructionKind, SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmx86Instruction* buildx86Instruction(X86InstructionKind, SgAsmOperandList *operands) ROSE_DEPRECATED;
SgAsmInstruction* buildMultibyteNopInstruction(int n) ROSE_DEPRECATED;
SgAsmx86Instruction *buildX86MultibyteNopInstruction(size_t nBytes);

// Build registers. Deprecated because ROSE doesn't have architecture-specific registers anymore. [Robb P. Matzke 2014-07-21]
// Use the SgAsmDirectRegisterExpression constructor instead.
SgAsmDirectRegisterExpression* buildSgAsmx86RegisterReferenceExpression(const RegisterDescriptor&) ROSE_DEPRECATED;
SgAsmDirectRegisterExpression* buildSgAsmArmRegisterReferenceExpression(const RegisterDescriptor&) ROSE_DEPRECATED;
SgAsmDirectRegisterExpression* buildSgAsmMipsRegisterReferenceExpression(const RegisterDescriptor&) ROSE_DEPRECATED;
SgAsmDirectRegisterExpression* buildSgAsmPowerpcRegisterReferenceExpression(const RegisterDescriptor&) ROSE_DEPRECATED;
   
// Building integer values generically (one of these per buildType function above)
SgAsmIntegerValueExpression* buildValueU1(bool);
SgAsmIntegerValueExpression* buildValueU8(uint8_t);
SgAsmIntegerValueExpression* buildValueU16le(uint16_t);
SgAsmIntegerValueExpression* buildValueU16be(uint16_t);
SgAsmIntegerValueExpression* buildValueU32le(uint32_t);
SgAsmIntegerValueExpression* buildValueU32be(uint32_t);
SgAsmIntegerValueExpression* buildValueU64le(uint64_t);
SgAsmIntegerValueExpression* buildValueU64be(uint64_t);
SgAsmIntegerValueExpression* buildValueI8(int8_t);
SgAsmIntegerValueExpression* buildValueI16le(int16_t);
SgAsmIntegerValueExpression* buildValueI16be(int16_t);
SgAsmIntegerValueExpression* buildValueI32le(int32_t);
SgAsmIntegerValueExpression* buildValueI32be(int32_t);
SgAsmIntegerValueExpression* buildValueI64le(int64_t);
SgAsmIntegerValueExpression* buildValueI64be(int64_t);
SgAsmFloatValueExpression* buildValueIeee754Binary32le(double);
SgAsmFloatValueExpression* buildValueIeee754Binary32be(double);
SgAsmFloatValueExpression* buildValueIeee754Binary64le(double);
SgAsmFloatValueExpression* buildValueIeee754Binary64be(double);

// Building integer values with x86-specific type names
SgAsmIntegerValueExpression* buildValueX86Byte(uint8_t);
SgAsmIntegerValueExpression* buildValueX86Word(uint16_t);
SgAsmIntegerValueExpression* buildValueX86DWord(uint32_t);
SgAsmIntegerValueExpression* buildValueX86QWord(uint64_t);
SgAsmFloatValueExpression* buildValueX86Float32(double);
SgAsmFloatValueExpression* buildValueX86Float64(double);
SgAsmFloatValueExpression* buildValueX86Float80(double);

// Building integer values with x86-specific type names.
// These are deprecated because they lack "X86" in their names [Robb P. Matzke 2014-07-21].
SgAsmIntegerValueExpression* buildAsmByteValue(uint8_t) ROSE_DEPRECATED;
SgAsmIntegerValueExpression* buildAsmWordValue(uint16_t) ROSE_DEPRECATED;
SgAsmIntegerValueExpression* buildAsmDWordValue(uint32_t) ROSE_DEPRECATED;
SgAsmIntegerValueExpression* buildAsmQWordValue(uint64_t) ROSE_DEPRECATED;

// Building integer values with x86-specific type names.
// These are deprecated because they should have been named "build" instead of "make"
SgAsmIntegerValueExpression* makeByteValue(uint8_t) ROSE_DEPRECATED;
SgAsmIntegerValueExpression* makeWordValue(uint16_t) ROSE_DEPRECATED;
SgAsmIntegerValueExpression* makeDWordValue(uint32_t) ROSE_DEPRECATED;
SgAsmIntegerValueExpression* makeQWordValue(uint64_t) ROSE_DEPRECATED;

// Operators
SgAsmBinaryAdd* buildAddExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinarySubtract* buildSubtractExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinaryAddPreupdate* buildAddPreupdateExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinarySubtractPreupdate* buildSubtractPreupdateExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinaryAddPostupdate* buildAddPostupdateExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinarySubtractPostupdate* buildSubtractPostupdateExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinaryMultiply* buildMultiplyExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinaryLsl* buildLslExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinaryLsr* buildLsrExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinaryAsr* buildAsrExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmBinaryRor* buildRorExpression(SgAsmExpression *lhs, SgAsmExpression *rhs);
SgAsmUnaryRrx* buildRrxExpression(SgAsmExpression *lhs);
SgAsmUnaryArmSpecialRegisterList *buildArmSpecialRegisterList(SgAsmExpression *lhs);
SgAsmExprListExp* buildExprListExpression();
SgAsmMemoryReferenceExpression* buildMemoryReferenceExpression(SgAsmExpression *addr, SgAsmExpression *segment=NULL,
                                                               SgAsmType *type=NULL);

// Operators (deprecated because they should have been named "build" rather than "make" [Robb P. Matzke 2014-07-21])
SgAsmBinaryAdd* makeAdd(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinarySubtract* makeSubtract(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinaryAddPreupdate* makeAddPreupdate(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinarySubtractPreupdate* makeSubtractPreupdate(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinaryAddPostupdate* makeAddPostupdate(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinarySubtractPostupdate* makeSubtractPostupdate(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinaryMultiply* makeMul(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinaryLsl* makeLsl(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinaryLsr* makeLsr(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinaryAsr* makeAsr(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmBinaryRor* makeRor(SgAsmExpression *lhs, SgAsmExpression *rhs) ROSE_DEPRECATED;
SgAsmUnaryRrx* makeRrx(SgAsmExpression *lhs) ROSE_DEPRECATED;
SgAsmUnaryArmSpecialRegisterList* makeArmSpecialRegisterList(SgAsmExpression *lhs) ROSE_DEPRECATED;
SgAsmExprListExp* makeExprListExp() ROSE_DEPRECATED;
SgAsmMemoryReferenceExpression* makeMemoryReference(SgAsmExpression *addr, SgAsmExpression *segment=NULL,
                                                    SgAsmType *type=NULL) ROSE_DEPRECATED;

template <typename Insn>
inline Insn* appendOperand(Insn* insn, SgAsmExpression* op) {
    SgAsmOperandList* operands = insn->get_operandList();
    operands->get_operands().push_back(op);
    op->set_parent(operands);
    return insn; // For chaining this operation
}

} // namespace

#endif
