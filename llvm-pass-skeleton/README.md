**LLVM-PASS-SKELETON**
========================

How to build llvm pass
=======================
git clone "this repo"   
cd "this repo path"  
mkdir build  
cmake ../  
cmake --build .   

How to use llvm pass
=======================
Prepare the source file to be the target.  
clang -emit-llvm -c "your_source_code.c"  
opt -load="the absolute path of llvm-pass-library.so" -skeleton source.bc -o out.bc
