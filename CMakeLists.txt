cmake_minimum_required (VERSION 3.1)
project (DAS)

INCLUDE(./CMakeCommon.txt)

IF(MSVC)
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)
ENDIF()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)

FIND_XXD()
FIND_FLEX_AND_BISON()

SETUP_COMPILER()

FLEX(src/parser/ds_lexer.lpp)
BISON(src/parser/ds_parser.ypp)

SET(PARSER_GENERATED_SRC
src/parser/ds_parser.hpp
src/parser/ds_parser.cpp
src/parser/ds_parser.output
src/parser/ds_lexer.cpp
)

SET(PARSER_SRC
src/parser/ds_parser.ypp
src/parser/ds_lexer.lpp
)
list(SORT PARSER_SRC)
SOURCE_GROUP_FILES("parser" PARSER_SRC)
SOURCE_GROUP_FILES("parser/generated" PARSER_GENERATED_SRC)

IF(MSVC)
    # Don't use precompiled headers with flex/bison generated files
    FOREACH(file ${PARSER_GENERATED_SRC})
        SET_SOURCE_FILES_PROPERTIES(${file} PROPERTIES COMPILE_FLAGS "/Y-" )
    ENDFOREACH()
ENDIF()

SET(VECMATH_SRC
include/vecmath/dag_vecMath.h
include/vecmath/dag_vecMathDecl.h
include/vecmath/dag_vecMath_common.h
include/vecmath/dag_vecMath_const.h
include/vecmath/dag_vecMath_neon.h
include/vecmath/dag_vecMath_pc_sse.h
)
list(SORT VECMATH_SRC)
SOURCE_GROUP_FILES("vecmath" VECMATH_SRC)

SET(AST_SRC
src/ast/ast.cpp
src/ast/ast_generate.cpp
src/ast/ast_simulate.cpp
src/ast/ast_typedecl.cpp
src/ast/ast_match.cpp
src/ast/ast_module.cpp
src/ast/ast_print.cpp
src/ast/ast_aot_cpp.cpp
src/ast/ast_plot.cpp
src/ast/ast_infer_type.cpp
src/ast/ast_lint.cpp
src/ast/ast_allocate_stack.cpp
src/ast/ast_const_folding.cpp
src/ast/ast_block_folding.cpp
src/ast/ast_unused.cpp
src/ast/ast_annotations.cpp
src/ast/ast_export.cpp
src/ast/ast_parse.cpp
src/ast/ast_debug_info_helper.cpp
src/ast/ast_handle.cpp
src/ast/ast_runtime_helpers.cpp
include/daScript/ast/compilation_errors.h
include/daScript/ast/ast_typedecl.h
include/daScript/ast/ast_typefactory.h
include/daScript/ast/ast.h
include/daScript/ast/ast_expressions.h
include/daScript/ast/ast_visitor.h
include/daScript/ast/ast_generate.h
include/daScript/ast/ast_match.h
include/daScript/ast/ast_interop.h
include/daScript/ast/ast_handle.h
include/daScript/ast/ast_policy_types.h
)
list(SORT AST_SRC)
SOURCE_GROUP_FILES("ast" AST_SRC)

SET(BUILTIN_SRC
src/builtin/module_builtin.h
src/builtin/module_builtin.cpp
src/builtin/module_builtin_misc_types.cpp
src/builtin/module_builtin_runtime.cpp
src/builtin/module_builtin_runtime_sort.cpp
src/builtin/module_builtin_vector.cpp
src/builtin/module_builtin_vector_ctor.cpp
src/builtin/module_builtin_array.cpp
src/builtin/module_builtin_das.cpp
src/builtin/module_builtin_math.cpp
src/builtin/module_builtin_random.cpp
src/builtin/module_builtin_string.cpp
src/builtin/module_builtin_rtti.h
src/builtin/module_builtin_rtti.cpp
src/builtin/module_builtin_ast.cpp
src/builtin/module_builtin_fio.cpp
src/builtin/module_builtin_network.cpp
src/builtin/module_file_access.cpp
src/builtin/builtin.das.inc
src/builtin/builtin.das
src/builtin/fio.das.inc
src/builtin/fio.das
src/builtin/rtti.das.inc
src/builtin/rtti.das
src/builtin/ast.das.inc
src/builtin/ast.das
src/builtin/network.das.inc
src/builtin/network.das
)
list(SORT BUILTIN_SRC)
SOURCE_GROUP_FILES("module builtin" BUILTIN_SRC)
XXD(src/builtin/builtin.das)
XXD(src/builtin/fio.das)
XXD(src/builtin/rtti.das)
XXD(src/builtin/ast.das)
XXD(src/builtin/network.das)

SET(MISC_SRC
include/daScript/misc/enums.h
include/daScript/misc/function_traits.h
include/daScript/misc/hal.h
include/daScript/misc/fpe.h
include/daScript/misc/copy_bytes.h
include/daScript/misc/platform.h
include/daScript/misc/vectypes.h
include/daScript/misc/arraytype.h
include/daScript/misc/rangetype.h
include/daScript/misc/string_writer.h
include/daScript/misc/type_name.h
include/daScript/misc/lookup1.h
include/daScript/misc/memory_model.h
include/daScript/misc/fnv.h
include/daScript/misc/smart_ptr.h
include/daScript/misc/free_list.h
include/daScript/misc/sysos.h
src/misc//sysos.cpp
src/misc/string_writer.cpp
src/misc/memory_model.cpp
)
list(SORT MISC_SRC)
SOURCE_GROUP_FILES("misc" MISC_SRC)

SET(SIMULATE_FUSION_SRC
src/simulate/simulate_fusion.cpp
src/simulate/simulate_fusion_op1.cpp
src/simulate/simulate_fusion_op1_return.cpp
src/simulate/simulate_fusion_ptrfdr.cpp
src/simulate/simulate_fusion_op2.cpp
src/simulate/simulate_fusion_op2_set.cpp
src/simulate/simulate_fusion_op2_bool.cpp
src/simulate/simulate_fusion_op2_bin.cpp
src/simulate/simulate_fusion_op2_vec.cpp
src/simulate/simulate_fusion_op2_set_vec.cpp
src/simulate/simulate_fusion_op2_bool_vec.cpp
src/simulate/simulate_fusion_op2_bin_vec.cpp
src/simulate/simulate_fusion_op2_scalar_vec.cpp
src/simulate/simulate_fusion_at.cpp
src/simulate/simulate_fusion_at_array.cpp
src/simulate/simulate_fusion_tableindex.cpp
src/simulate/simulate_fusion_misc_copy.cpp
src/simulate/simulate_fusion_call1.cpp
src/simulate/simulate_fusion_call2.cpp
src/simulate/simulate_fusion_if.cpp
include/daScript/simulate/simulate_fusion.h
include/daScript/simulate/simulate_fusion_op1.h
include/daScript/simulate/simulate_fusion_op1_impl.h
include/daScript/simulate/simulate_fusion_op1_perm.h
include/daScript/simulate/simulate_fusion_op1_set_impl.h
include/daScript/simulate/simulate_fusion_op1_set_perm.h
include/daScript/simulate/simulate_fusion_op1_reg.h
include/daScript/simulate/simulate_fusion_op2.h
include/daScript/simulate/simulate_fusion_op2_impl.h
include/daScript/simulate/simulate_fusion_op2_perm.h
include/daScript/simulate/simulate_fusion_op2_set_impl.h
include/daScript/simulate/simulate_fusion_op2_set_perm.h
include/daScript/simulate/simulate_fusion_op2_vec_settings.h
)
list(SORT SIMULATE_FUSION_SRC)
SOURCE_GROUP_FILES("fusion" SIMULATE_FUSION_SRC)

SET(SIMULATE_SRC
src/hal/performance_time.cpp
include/daScript/misc/performance_time.h
src/hal/debug_break.cpp
src/hal/project_specific.cpp
src/hal/project_specific_file_info.cpp
include/daScript/misc/network.h
src/misc/network.cpp
src/simulate/hash.cpp
src/simulate/debug_info.cpp
src/simulate/runtime_string.cpp
src/simulate/runtime_array.cpp
src/simulate/runtime_table.cpp
src/simulate/runtime_range.cpp
src/simulate/runtime_profile.cpp
src/simulate/simulate.cpp
src/simulate/simulate_gc.cpp
src/simulate/simulate_visit.cpp
src/simulate/simulate_print.cpp
src/simulate/simulate_fn_hash.cpp
include/daScript/simulate/cast.h
include/daScript/simulate/hash.h
include/daScript/simulate/heap.h
src/simulate/heap.cpp
include/daScript/simulate/debug_info.h
include/daScript/simulate/interop.h
include/daScript/simulate/runtime_string.h
include/daScript/simulate/runtime_string_delete.h
include/daScript/simulate/runtime_array.h
include/daScript/simulate/runtime_table.h
include/daScript/simulate/runtime_table_nodes.h
include/daScript/simulate/runtime_range.h
include/daScript/simulate/runtime_profile.h
include/daScript/simulate/runtime_matrices.h
include/daScript/simulate/simulate.h
include/daScript/simulate/simulate_nodes.h
include/daScript/simulate/simulate_visit.h
include/daScript/simulate/simulate_visit_op.h
include/daScript/simulate/simulate_visit_op_undef.h
include/daScript/simulate/sim_policy.h
src/simulate/data_walker.cpp
include/daScript/simulate/data_walker.h
src/simulate/debug_print.cpp
include/daScript/simulate/debug_print.h
include/daScript/simulate/for_each.h
include/daScript/simulate/bind_enum.h
include/daScript/simulate/bin_serializer.h
src/simulate/bin_serializer.cpp
include/daScript/simulate/aot.h
include/daScript/simulate/aot_library.h
include/daScript/simulate/aot_builtin.h
include/daScript/simulate/aot_builtin_math.h
include/daScript/simulate/aot_builtin_matrix.h
include/daScript/simulate/aot_builtin_random.h
include/daScript/simulate/aot_builtin_time.h
include/daScript/simulate/aot_builtin_string.h
include/daScript/simulate/aot_builtin_fio.h
include/daScript/simulate/aot_builtin_rtti.h
include/daScript/simulate/aot_builtin_ast.h
include/daScript/simulate/fs_file_info.h
src/simulate/fs_file_info.cpp
)
list(SORT SIMULATE_SRC)
SOURCE_GROUP_FILES("simulate" SIMULATE_SRC)

SET(DAGOR_NOISE_SRC
include/dag_noise/dag_uint_noise.h
)
SOURCE_GROUP_FILES("dag_noise" DAGOR_NOISE_SRC)

SET(FLAT_HASH_MAP_SRC
include/ska/flat_hash_map.hpp
)
SOURCE_GROUP_FILES("flat_hash_map" FLAT_HASH_MAP_SRC)

SET(MAIN_SRC
include/daScript/daScript.h
include/daScript/daScriptModule.h
include/daScript/das_config.h
)
SOURCE_GROUP_FILES("main" MAIN_SRC)

file(GLOB DAS_LIB_SRC
"daslib/*.das"
)
list(SORT DAS_LIB_SRC)
SOURCE_GROUP_FILES("daslib" DSA_LIB_SRC)
list(SORT DAS_LIB_SRC)

include_directories(include)
ADD_LIBRARY(libDaScript ${VECMATH_SRC} ${AST_SRC} ${BUILTIN_SRC} ${MISC_SRC} ${SIMULATE_SRC}
    ${SIMULATE_FUSION_SRC} ${TEST_SRC} ${MAIN_SRC} ${PARSER_SRC} ${PARSER_GENERATED_SRC}
	${DAGOR_NOISE_SRC} ${FLAT_HASH_MAP_SRC} ${DAS_LIB_SRC})
SETUP_CPP11(libDaScript)

# AOT compiler

SET(DASAOT_MAIN_SRC
utils/dasAot/main.cpp
)
SOURCE_GROUP_FILES("main" DASAOT_MAIN_SRC)

add_executable(dasAot ${DASAOT_MAIN_SRC} )
TARGET_LINK_LIBRARIES(dasAot libDaScript libPathTracerHelper libDaScriptProfile libDaScriptTest libDasModuleUriparser libUriParser)
ADD_DEPENDENCIES(dasAot libDaScript libPathTracerHelper libDaScriptProfile libDaScriptTest libDasModuleUriparser libUriParser)
SETUP_CPP11(dasAot)

MACRO(DAS_AOT input genList mainTarget)
    get_filename_component(input_src ${input} ABSOLUTE)
    get_filename_component(input_dir ${input_src} DIRECTORY)
    get_filename_component(input_name ${input} NAME)
    set(out_dir ${input_dir}/_aot_generated)
    set(out_src ${out_dir}/${input_name}.cpp)
    file(MAKE_DIRECTORY ${out_dir})
	ADD_CUSTOM_COMMAND(
		DEPENDS ${input_src}
        DEPENDS dasAot
        OUTPUT  ${out_src}
        COMMENT "AOT precompiling ${input_src} -> ${out_src}"
        COMMAND dasAot ${input_src} ${out_src}
    )
    set(custom_name ${mainTarget}_${input_name}_aot)
    ADD_CUSTOM_TARGET(${custom_name}
        ALL DEPENDS ${out_src}
    )
    SET_TARGET_PROPERTIES(${custom_name} PROPERTIES FOLDER _${mainTarget}_aot)
    ADD_DEPENDENCIES(${mainTarget} ${custom_name})
    list(APPEND ${genList} ${out_src})
ENDMACRO()

MACRO(DAS_AOT_DIR inFiles genList mainTarget)
    FOREACH(inF ${inFiles})
        DAS_AOT(${inF} ${genList} ${mainTarget})
    ENDFOREACH()
ENDMACRO()

add_custom_target(dasAotStub)
SET(AOT_GENERATED_SRC)
DAS_AOT("examples/test/aot_dummy.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/ast_boost.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/functional.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/json.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/json_boost.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/regex.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/regex_boost.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/strings_boost.das" AOT_GENERATED_SRC dasAotStub)
DAS_AOT("daslib/rst.das" AOT_GENERATED_SRC dasAotStub)
SOURCE_GROUP_FILES("aot stub" AOT_GENERATED_SRC)

# libUriParser

SET(URIPARSER_SRCS
3rdparty/uriparser/src/UriCommon.c
3rdparty/uriparser/src/UriCompare.c
3rdparty/uriparser/src/UriEscape.c
3rdparty/uriparser/src/UriFile.c
3rdparty/uriparser/src/UriIp4.c
3rdparty/uriparser/src/UriIp4Base.c
3rdparty/uriparser/src/UriNormalize.c
3rdparty/uriparser/src/UriNormalizeBase.c
3rdparty/uriparser/src/UriParse.c
3rdparty/uriparser/src/UriParseBase.c
3rdparty/uriparser/src/UriQuery.c
3rdparty/uriparser/src/UriRecompose.c
3rdparty/uriparser/src/UriResolve.c
3rdparty/uriparser/src/UriShorten.c
)

ADD_LIBRARY(libUriParser STATIC ${URIPARSER_SRCS})
SETUP_CPP11(libUriParser)
target_compile_definitions(libUriParser PUBLIC URIPARSER_BUILD_CHAR)
target_compile_definitions(libUriParser PUBLIC URI_STATIC_BUILD)
target_include_directories(libUriParser PUBLIC
  ${CMAKE_SOURCE_DIR}/3rdparty/uriparser/include
)

# MODULE - uri parser

SET(MODULE_URIPARSE_MAIN_SRC
include/modules/uriparser/module_uriparser.h
src/modules/uriparser/module_uriparser.cpp
)

ADD_LIBRARY(libDasModuleUriparser ${MODULE_URIPARSE_MAIN_SRC})
SETUP_CPP11(libDasModuleUriparser)
target_include_directories(libDasModuleUriparser PUBLIC
  ${CMAKE_SOURCE_DIR}/3rdparty/uriparser/include
  include/modules/uriparser
)
ADD_DEPENDENCIES(libDasModuleUriparser libDaScript libUriParser)

# Continues development tool

SET(DASCONTDEV_MAIN_SRC
utils/dasContDev/main.cpp
)
SOURCE_GROUP_FILES("main" DASCONTDEV_MAIN_SRC)

add_executable(dasContDev ${DASCONTDEV_MAIN_SRC} ${AOT_GENERATED_SRC})
TARGET_LINK_LIBRARIES(dasContDev libDaScript libPathTracerHelper libDaScriptTest libDaScriptProfile libDasModuleUriparser libUriParser)
ADD_DEPENDENCIES(dasContDev libDaScript libPathTracerHelper libDaScriptTest libDaScriptProfile libDasModuleUriparser libUriParser)
SETUP_CPP11(dasContDev)
add_dependencies(dasContDev dasAotStub)

# PathTracer helper

SET(PATH_TRACER_HELPER_MAIN_SRC
examples/pathTracer/path_tracer_helper.h
examples/pathTracer/path_tracer_helper.cpp
)

ADD_LIBRARY(libPathTracerHelper ${PATH_TRACER_HELPER_MAIN_SRC})
SETUP_CPP11(libPathTracerHelper)
ADD_DEPENDENCIES(libPathTracerHelper libDaScript)

# PathTracer

SET(PATH_TRACER_MAIN_SRC
examples/pathTracer/main.cpp
examples/pathTracer/path_tracer_helper.h
examples/pathTracer/toy_path_tracer.das
)
SOURCE_GROUP_FILES("source" PATH_TRACER_MAIN_SRC)

add_custom_target(pathTracerAot)
SET(PATH_TRACER_GEN_SRC)
DAS_AOT(examples/pathTracer/toy_path_tracer.das PATH_TRACER_GEN_SRC pathTracerAot)
SOURCE_GROUP_FILES("generated" PATH_TRACER_GEN_SRC)

add_executable(pathTracer ${PATH_TRACER_MAIN_SRC} ${PATH_TRACER_GEN_SRC} ${AOT_GENERATED_SRC})
TARGET_LINK_LIBRARIES(pathTracer libDaScript libPathTracerHelper)
IF (UNIX)
  TARGET_LINK_LIBRARIES(pathTracer pthread)
ENDIF()
ADD_DEPENDENCIES(pathTracer libDaScript libPathTracerHelper)
TARGET_INCLUDE_DIRECTORIES(pathTracer PUBLIC examples/pathTracer)
SETUP_CPP11(pathTracer)
add_dependencies(pathTracer pathTracerAot dasAotStub)

# Stand alone command line compiler

SET(DASCRIPT_MAIN_SRC
utils/daScript/main.cpp
)
SOURCE_GROUP_FILES("main" DASCRIPT_MAIN_SRC)

add_executable(daScript ${DASCRIPT_MAIN_SRC} ${AOT_GENERATED_SRC})
TARGET_LINK_LIBRARIES(daScript libDaScript libPathTracerHelper libDaScriptTest libDaScriptProfile libDasModuleUriparser libUriParser)
ADD_DEPENDENCIES(daScript libDaScript libPathTracerHelper libDaScriptTest libDaScriptProfile libDasModuleUriparser libUriParser)
SETUP_CPP11(daScript)
add_dependencies(daScript dasAotStub)

# Test module

SET(TEST_MAIN_LIB_SRC
examples/test/test_handles.cpp
examples/test/test_enum.cpp
examples/test/module_unitTest.h
examples/test/unitTest.h
examples/test/unit_test.das.inc
examples/test/unit_test.das
)
SOURCE_GROUP_FILES("source" TEST_MAIN_LIB_SRC)

XXD(examples/test/unit_test.das)

ADD_LIBRARY(libDaScriptTest ${TEST_MAIN_LIB_SRC})
SETUP_CPP11(libDaScriptTest)
ADD_DEPENDENCIES(libDaScriptTest libDaScript)

# Test

file(GLOB UNIT_TEST_SRC
"examples/test/unit_tests/*.das"
)
list(SORT UNIT_TEST_SRC)
SOURCE_GROUP_FILES("examples/test/unit" UNIT_TEST_SRC)

file(GLOB COMPILATION_FAIL_TEST_SRC
"examples/test/compilation_fail_tests/*.das"
)
list(SORT COMPILATION_FAIL_TEST_SRC)
SOURCE_GROUP_FILES("examples/test/compilation fail" COMPILATION_FAIL_TEST_SRC)

file(GLOB OPTIMIZATION_SRC
"examples/test/optimizations/*.das"
)
list(SORT OPTIMIZATION_SRC)
SOURCE_GROUP_FILES("examples/test/optimizations" OPTIMIZATION_SRC)

file(GLOB RUNTIME_ERRORS_SRC
"examples/test/runtime_errors/*.das"
)
list(SORT RUNTIME_ERRORS_SRC)
SOURCE_GROUP_FILES("examples/test/runtime_errors" RUNTIME_ERRORS_SRC)

file(GLOB MIX_TEST_SRC
"examples/test/*.das"
)
list(SORT MIX_TEST_SRC)
SOURCE_GROUP_FILES("examples/test/mix" MIX_TEST_SRC)

file(GLOB_RECURSE MODULE_TEST_SRC
"examples/test/module/*.*"
)
list(SORT MODULE_TEST_SRC)
SOURCE_GROUP_FILES("examples/test/module" MODULE_TEST_SRC)

SET(TEST_MAIN_SRC
examples/test/main.cpp
examples/test/unitTest.h
)
list(SORT TEST_MAIN_SRC)
SOURCE_GROUP_FILES("source" TEST_MAIN_SRC)

add_custom_target(daScriptTestAot)
SET(TEST_GENERATED_SRC)
DAS_AOT_DIR("${UNIT_TEST_SRC}" TEST_GENERATED_SRC daScriptTestAot)
#DAS_AOT("examples/test/hello_world.das" TEST_GENERATED_SRC daScriptTestAot)
SOURCE_GROUP_FILES("generated" TEST_GENERATED_SRC)

add_executable(daScriptTest ${UNIT_TEST_SRC} ${COMPILATION_FAIL_TEST_SRC} ${MIX_TEST_SRC} ${MODULE_TEST_SRC}
    ${TEST_MAIN_SRC} ${OPTIMIZATION_SRC} ${RUNTIME_ERRORS_SRC} ${TEST_GENERATED_SRC} ${AOT_GENERATED_SRC})
TARGET_LINK_LIBRARIES(daScriptTest libDaScript libDaScriptTest libDaScriptProfile libDasModuleUriparser libUriParser)
ADD_DEPENDENCIES(daScriptTest libDaScript libDaScriptTest libDaScriptProfile libDasModuleUriparser libUriParser)
TARGET_INCLUDE_DIRECTORIES(daScriptTest PUBLIC examples/test)
SETUP_CPP11(daScriptTest)
add_dependencies(daScriptTest daScriptTestAot dasAotStub)

# Profile module

SET(PROFILE_MAIN_LIB_SRC
examples/profile/test_profile.cpp
examples/profile/test_profile.h
)
SOURCE_GROUP_FILES("source" PROFILE_MAIN_LIB_SRC)

ADD_LIBRARY(libDaScriptProfile ${PROFILE_MAIN_LIB_SRC})
SETUP_CPP11(libDaScriptProfile)
ADD_DEPENDENCIES(libDaScriptProfile libDaScript)

# Profile

file(GLOB PROFILE_SRC
"examples/profile/tests/*.das"
)
list(SORT PROFILE_SRC)
SOURCE_GROUP_FILES("profile" PROFILE_SRC)

SET(PROFILE_MAIN_SRC
examples/profile/main.cpp
examples/profile/test_profile.h
)
list(SORT PROFILE_MAIN_SRC)
SOURCE_GROUP_FILES("source" PROFILE_MAIN_SRC)

add_custom_target(daScriptProfileAot)
SET(PROFILE_GENERATED_SRC)
DAS_AOT_DIR("${PROFILE_SRC}" PROFILE_GENERATED_SRC daScriptProfileAot)
SOURCE_GROUP_FILES("generated" PROFILE_GENERATED_SRC)

add_executable(daScriptProfile ${PROFILE_SRC} ${PROFILE_MAIN_SRC} ${PROFILE_GENERATED_SRC} ${AOT_GENERATED_SRC})
TARGET_INCLUDE_DIRECTORIES(daScriptProfile PUBLIC examples/profile)
TARGET_LINK_LIBRARIES(daScriptProfile libDaScript libDaScriptProfile)
ADD_DEPENDENCIES(daScriptProfile libDaScript dasAot libDaScriptProfile)
SETUP_CPP11(daScriptProfile)
add_dependencies(daScriptProfile daScriptProfileAot dasAotStub)

