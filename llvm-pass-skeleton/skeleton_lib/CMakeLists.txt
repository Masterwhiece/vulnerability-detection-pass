add_library(SkeletonPass MODULE
    # List your source files here.
    skeleton.cpp
)

target_compile_features(SkeletonPass PRIVATE cxx_range_for cxx_auto_type)

