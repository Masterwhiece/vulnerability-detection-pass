#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Analysis/Utils/Local.h"  // EmitGEPOffset() func
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"

using namespace llvm;

class SkeletonPass: public ModulePass{
    public:
        static char ID;
        SkeletonPass() : ModulePass(ID) {}

        virtual void getAnalysisUsage(AnalysisUsage& AU) const override;
        virtual bool runOnModule(Module &M) override;

        bool func(); 
};
