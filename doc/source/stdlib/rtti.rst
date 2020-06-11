
.. _stdlib_rtti:

================================
Runtime type information library
================================

++++++++++++
Type aliases
++++++++++++

.. _alias_FileAccessPtr:

.. das:attribute:: FileAccessPtr = FileAccessPtr

to be documented

.. _alias_ProgramFlags:

.. das:attribute:: ProgramFlags is a bitfield

+-----------------+-+--+
+failToCompile    +0+1 +
+-----------------+-+--+
+unsafe           +1+2 +
+-----------------+-+--+
+isCompiling      +2+4 +
+-----------------+-+--+
+isSimulating     +3+8 +
+-----------------+-+--+
+isCompilingMacros+4+16+
+-----------------+-+--+
+needMacroModule  +5+32+
+-----------------+-+--+


to be documented

.. _alias_RttiValue:

.. das:attribute:: RttiValueis a variant type

+-------+------+
+tBool  +bool  +
+-------+------+
+tInt   +int   +
+-------+------+
+tUInt  +uint  +
+-------+------+
+tInt64 +int64 +
+-------+------+
+tUInt64+uint64+
+-------+------+
+tFloat +float +
+-------+------+
+tDouble+double+
+-------+------+
+tString+string+
+-------+------+
+nothing+any   +
+-------+------+


to be documented

++++++++++++
Enumerations
++++++++++++

.. _enum_rtti_CompilationError:

.. das:attribute:: CompilationError

to be documented

+-----------------------------------+-----+
+unspecified                        +0    +
+-----------------------------------+-----+
+mismatching_parentheses            +10001+
+-----------------------------------+-----+
+mismatching_curly_bracers          +10002+
+-----------------------------------+-----+
+string_constant_exceeds_file       +10003+
+-----------------------------------+-----+
+string_constant_exceeds_line       +10004+
+-----------------------------------+-----+
+unexpected_close_comment           +10005+
+-----------------------------------+-----+
+integer_constant_out_of_range      +10006+
+-----------------------------------+-----+
+comment_contains_eof               +10007+
+-----------------------------------+-----+
+invalid_escape_sequence            +10008+
+-----------------------------------+-----+
+invalid_line_directive             +10009+
+-----------------------------------+-----+
+syntax_error                       +20000+
+-----------------------------------+-----+
+invalid_type                       +30101+
+-----------------------------------+-----+
+invalid_return_type                +30102+
+-----------------------------------+-----+
+invalid_argument_type              +30103+
+-----------------------------------+-----+
+invalid_structure_field_type       +30104+
+-----------------------------------+-----+
+invalid_array_type                 +30105+
+-----------------------------------+-----+
+invalid_table_type                 +30106+
+-----------------------------------+-----+
+invalid_argument_count             +30107+
+-----------------------------------+-----+
+invalid_variable_type              +30108+
+-----------------------------------+-----+
+invalid_new_type                   +30109+
+-----------------------------------+-----+
+invalid_index_type                 +30110+
+-----------------------------------+-----+
+invalid_annotation                 +30111+
+-----------------------------------+-----+
+invalid_swizzle_mask               +30112+
+-----------------------------------+-----+
+invalid_initialization_type        +30113+
+-----------------------------------+-----+
+invalid_with_type                  +30114+
+-----------------------------------+-----+
+invalid_override                   +30115+
+-----------------------------------+-----+
+invalid_name                       +30116+
+-----------------------------------+-----+
+invalid_array_dimension            +30117+
+-----------------------------------+-----+
+invalid_iteration_source           +30118+
+-----------------------------------+-----+
+invalid_loop                       +30119+
+-----------------------------------+-----+
+invalid_label                      +30120+
+-----------------------------------+-----+
+invalid_enumeration                +30121+
+-----------------------------------+-----+
+invalid_option                     +30122+
+-----------------------------------+-----+
+invalid_member_function            +30123+
+-----------------------------------+-----+
+function_already_declared          +30201+
+-----------------------------------+-----+
+argument_already_declared          +30202+
+-----------------------------------+-----+
+local_variable_already_declared    +30203+
+-----------------------------------+-----+
+global_variable_already_declared   +30204+
+-----------------------------------+-----+
+structure_field_already_declared   +30205+
+-----------------------------------+-----+
+structure_already_declared         +30206+
+-----------------------------------+-----+
+structure_already_has_initializer  +30207+
+-----------------------------------+-----+
+enumeration_already_declared       +30208+
+-----------------------------------+-----+
+enumeration_value_already_declared +30209+
+-----------------------------------+-----+
+type_alias_already_declared        +30210+
+-----------------------------------+-----+
+field_already_initialized          +30211+
+-----------------------------------+-----+
+type_not_found                     +30301+
+-----------------------------------+-----+
+structure_not_found                +30302+
+-----------------------------------+-----+
+operator_not_found                 +30303+
+-----------------------------------+-----+
+function_not_found                 +30304+
+-----------------------------------+-----+
+variable_not_found                 +30305+
+-----------------------------------+-----+
+handle_not_found                   +30306+
+-----------------------------------+-----+
+annotation_not_found               +30307+
+-----------------------------------+-----+
+enumeration_not_found              +30308+
+-----------------------------------+-----+
+enumeration_value_not_found        +30309+
+-----------------------------------+-----+
+type_alias_not_found               +30310+
+-----------------------------------+-----+
+bitfield_not_found                 +30311+
+-----------------------------------+-----+
+cant_initialize                    +30401+
+-----------------------------------+-----+
+cant_dereference                   +30501+
+-----------------------------------+-----+
+cant_index                         +30502+
+-----------------------------------+-----+
+cant_get_field                     +30503+
+-----------------------------------+-----+
+cant_write_to_const                +30504+
+-----------------------------------+-----+
+cant_move_to_const                 +30505+
+-----------------------------------+-----+
+cant_write_to_non_reference        +30506+
+-----------------------------------+-----+
+cant_copy                          +30507+
+-----------------------------------+-----+
+cant_move                          +30508+
+-----------------------------------+-----+
+cant_pass_temporary                +30509+
+-----------------------------------+-----+
+condition_must_be_bool             +30601+
+-----------------------------------+-----+
+condition_must_be_static           +30602+
+-----------------------------------+-----+
+cant_pipe                          +30701+
+-----------------------------------+-----+
+invalid_block                      +30801+
+-----------------------------------+-----+
+return_or_break_in_finally         +30802+
+-----------------------------------+-----+
+module_not_found                   +30901+
+-----------------------------------+-----+
+module_already_has_a_name          +30902+
+-----------------------------------+-----+
+cant_new_handle                    +31001+
+-----------------------------------+-----+
+bad_delete                         +31002+
+-----------------------------------+-----+
+cant_infer_generic                 +31100+
+-----------------------------------+-----+
+cant_infer_missing_initializer     +31101+
+-----------------------------------+-----+
+cant_infer_mismatching_restrictions+31102+
+-----------------------------------+-----+
+invalid_cast                       +31200+
+-----------------------------------+-----+
+incompatible_cast                  +31201+
+-----------------------------------+-----+
+unsafe                             +31300+
+-----------------------------------+-----+
+index_out_of_range                 +31400+
+-----------------------------------+-----+
+expecting_return_value             +32101+
+-----------------------------------+-----+
+not_expecting_return_value         +32102+
+-----------------------------------+-----+
+invalid_return_semantics           +32103+
+-----------------------------------+-----+
+invalid_yield                      +32104+
+-----------------------------------+-----+
+typeinfo_reference                 +39901+
+-----------------------------------+-----+
+typeinfo_auto                      +39902+
+-----------------------------------+-----+
+typeinfo_undefined                 +39903+
+-----------------------------------+-----+
+typeinfo_dim                       +39904+
+-----------------------------------+-----+
+typeinfo_macro_error               +39905+
+-----------------------------------+-----+
+static_assert_failed               +40100+
+-----------------------------------+-----+
+run_failed                         +40101+
+-----------------------------------+-----+
+annotation_failed                  +40102+
+-----------------------------------+-----+
+concept_failed                     +40103+
+-----------------------------------+-----+
+not_all_paths_return_value         +40200+
+-----------------------------------+-----+
+assert_with_side_effects           +40201+
+-----------------------------------+-----+
+only_fast_aot_no_cpp_name          +40202+
+-----------------------------------+-----+
+aot_side_effects                   +40203+
+-----------------------------------+-----+
+no_global_heap                     +40204+
+-----------------------------------+-----+
+no_global_variables                +40205+
+-----------------------------------+-----+
+unused_function_argument           +40206+
+-----------------------------------+-----+
+unsafe_function                    +40207+
+-----------------------------------+-----+
+too_many_infer_passes              +41000+
+-----------------------------------+-----+
+missing_node                       +50100+
+-----------------------------------+-----+


.. _enum_rtti_ConstMatters:

.. das:attribute:: ConstMatters

to be documented

+---+-+
+no +0+
+---+-+
+yes+1+
+---+-+


.. _enum_rtti_RefMatters:

.. das:attribute:: RefMatters

to be documented

+---+-+
+no +0+
+---+-+
+yes+1+
+---+-+


.. _enum_rtti_TemporaryMatters:

.. das:attribute:: TemporaryMatters

to be documented

+---+-+
+no +0+
+---+-+
+yes+1+
+---+-+


.. _enum_rtti_Type:

.. das:attribute:: Type

to be documented

+--------------+--+
+none          +0 +
+--------------+--+
+autoinfer     +1 +
+--------------+--+
+alias         +2 +
+--------------+--+
+fakeContext   +3 +
+--------------+--+
+fakeLineInfo  +4 +
+--------------+--+
+anyArgument   +5 +
+--------------+--+
+tVoid         +6 +
+--------------+--+
+tBool         +7 +
+--------------+--+
+tInt64        +12+
+--------------+--+
+tUInt64       +13+
+--------------+--+
+tInt          +14+
+--------------+--+
+tInt2         +15+
+--------------+--+
+tInt3         +16+
+--------------+--+
+tInt4         +17+
+--------------+--+
+tUInt         +18+
+--------------+--+
+tUInt2        +19+
+--------------+--+
+tUInt3        +20+
+--------------+--+
+tUInt4        +21+
+--------------+--+
+tFloat        +22+
+--------------+--+
+tFloat2       +23+
+--------------+--+
+tFloat3       +24+
+--------------+--+
+tFloat4       +25+
+--------------+--+
+tDouble       +26+
+--------------+--+
+tRange        +27+
+--------------+--+
+tURange       +28+
+--------------+--+
+tString       +29+
+--------------+--+
+tStructure    +30+
+--------------+--+
+tHandle       +31+
+--------------+--+
+tEnumeration  +32+
+--------------+--+
+tPointer      +36+
+--------------+--+
+tFunction     +37+
+--------------+--+
+tLambda       +38+
+--------------+--+
+tIterator     +39+
+--------------+--+
+tArray        +40+
+--------------+--+
+tTable        +41+
+--------------+--+
+tBlock        +42+
+--------------+--+
+tInt8         +8 +
+--------------+--+
+tUInt8        +9 +
+--------------+--+
+tInt16        +10+
+--------------+--+
+tUInt16       +11+
+--------------+--+
+tTuple        +43+
+--------------+--+
+tEnumeration8 +33+
+--------------+--+
+tEnumeration16+34+
+--------------+--+
+tVariant      +44+
+--------------+--+
+tBitfield     +35+
+--------------+--+


++++++++++++++++++
Handled structures
++++++++++++++++++

.. _handle_rtti_Annotation:

.. das:attribute:: Annotation

Annotation fields are

+-------+--------------------------------------------------------+
+_module+ :ref:`rtti::Module <handle_rtti_Module>` ?             +
+-------+--------------------------------------------------------+
+cppName+ :ref:`builtin::das_string <handle_builtin_das_string>` +
+-------+--------------------------------------------------------+
+name   + :ref:`builtin::das_string <handle_builtin_das_string>` +
+-------+--------------------------------------------------------+


Annotation properties are

+--------------------------+----+
+isTypeAnnotation          +bool+
+--------------------------+----+
+isBasicStructureAnnotation+bool+
+--------------------------+----+


to be documented


.. _handle_rtti_AnnotationArgument:

.. das:attribute:: AnnotationArgument

AnnotationArgument fields are

+---------+--------------------------------------------------------+
+fValue   +float                                                   +
+---------+--------------------------------------------------------+
+iValue   +int                                                     +
+---------+--------------------------------------------------------+
+name     + :ref:`builtin::das_string <handle_builtin_das_string>` +
+---------+--------------------------------------------------------+
+sValue   + :ref:`builtin::das_string <handle_builtin_das_string>` +
+---------+--------------------------------------------------------+
+bValue   +bool                                                    +
+---------+--------------------------------------------------------+
+basicType+ :ref:`rtti::Type <enum_rtti_Type>`                     +
+---------+--------------------------------------------------------+


to be documented


.. _handle_rtti_AnnotationDeclaration:

.. das:attribute:: AnnotationDeclaration

AnnotationDeclaration fields are

+----------+--------------------------------------------------------------------------+
+annotation+smart_ptr< :ref:`rtti::Annotation <handle_rtti_Annotation>` >             +
+----------+--------------------------------------------------------------------------+
+arguments + :ref:`rtti::AnnotationArgumentList <handle_rtti_AnnotationArgumentList>` +
+----------+--------------------------------------------------------------------------+


to be documented


.. _handle_rtti_BasicStructureAnnotation:

.. das:attribute:: BasicStructureAnnotation

BasicStructureAnnotation fields are

+-------+--------------------------------------------------------+
+cppName+ :ref:`builtin::das_string <handle_builtin_das_string>` +
+-------+--------------------------------------------------------+
+name   + :ref:`builtin::das_string <handle_builtin_das_string>` +
+-------+--------------------------------------------------------+


BasicStructureAnnotation properties are

+----------+---+
+fieldCount+int+
+----------+---+


to be documented


.. _handle_rtti_EnumInfo:

.. das:attribute:: EnumInfo

EnumInfo fields are

+-----+------+
+count+uint  +
+-----+------+
+name +string+
+-----+------+
+hash +uint  +
+-----+------+


to be documented


.. _handle_rtti_EnumValueInfo:

.. das:attribute:: EnumValueInfo

EnumValueInfo fields are

+-----+------+
+value+int64 +
+-----+------+
+name +string+
+-----+------+


to be documented


.. _handle_rtti_Error:

.. das:attribute:: Error

Error fields are

+-----+------------------------------------------------------------+
+fixme+ :ref:`builtin::das_string <handle_builtin_das_string>`     +
+-----+------------------------------------------------------------+
+at   + :ref:`rtti::LineInfo <handle_rtti_LineInfo>`               +
+-----+------------------------------------------------------------+
+what + :ref:`builtin::das_string <handle_builtin_das_string>`     +
+-----+------------------------------------------------------------+
+extra+ :ref:`builtin::das_string <handle_builtin_das_string>`     +
+-----+------------------------------------------------------------+
+cerr + :ref:`rtti::CompilationError <enum_rtti_CompilationError>` +
+-----+------------------------------------------------------------+


to be documented


.. _handle_rtti_FileAccess:

.. das:attribute:: FileAccess

to be documented


.. _handle_rtti_FileInfo:

.. das:attribute:: FileInfo

FileInfo fields are

+------------+--------------------------------------------------------+
+tabSize     +int                                                     +
+------------+--------------------------------------------------------+
+name        + :ref:`builtin::das_string <handle_builtin_das_string>` +
+------------+--------------------------------------------------------+
+sourceLength+uint                                                    +
+------------+--------------------------------------------------------+


FileInfo properties are

+------+------------+
+source+string const+
+------+------------+


to be documented


.. _handle_rtti_FuncInfo:

.. das:attribute:: FuncInfo

FuncInfo fields are

+---------+-----------------------------------------------+
+stackSize+uint                                           +
+---------+-----------------------------------------------+
+result   + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>` ?+
+---------+-----------------------------------------------+
+count    +uint                                           +
+---------+-----------------------------------------------+
+cppName  +string                                         +
+---------+-----------------------------------------------+
+name     +string                                         +
+---------+-----------------------------------------------+
+hash     +uint                                           +
+---------+-----------------------------------------------+
+flags    +uint                                           +
+---------+-----------------------------------------------+


to be documented


.. _handle_rtti_LineInfo:

.. das:attribute:: LineInfo

LineInfo fields are

+-----------+-----------------------------------------------+
+last_column+uint                                           +
+-----------+-----------------------------------------------+
+line       +uint                                           +
+-----------+-----------------------------------------------+
+last_line  +uint                                           +
+-----------+-----------------------------------------------+
+column     +uint                                           +
+-----------+-----------------------------------------------+
+fileInfo   + :ref:`rtti::FileInfo <handle_rtti_FileInfo>` ?+
+-----------+-----------------------------------------------+


to be documented


.. _handle_rtti_Module:

.. das:attribute:: Module

Module fields are

+----+--------------------------------------------------------+
+name+ :ref:`builtin::das_string <handle_builtin_das_string>` +
+----+--------------------------------------------------------+


to be documented


.. _handle_rtti_Program:

.. das:attribute:: Program

Program fields are

+------+------------------------------------------------------------+
+flags + :ref:`ProgramFlags <alias_ProgramFlags>`                   +
+------+------------------------------------------------------------+
+errors+ :ref:`rtti::dasvector`Error <handle_rtti_dasvector`Error>` +
+------+------------------------------------------------------------+


to be documented


.. _handle_rtti_StructInfo:

.. das:attribute:: StructInfo

StructInfo fields are

+-----------+------+
+size       +uint  +
+-----------+------+
+initializer+int   +
+-----------+------+
+count      +uint  +
+-----------+------+
+name       +string+
+-----------+------+
+hash       +uint  +
+-----------+------+


to be documented


.. _handle_rtti_TypeAnnotation:

.. das:attribute:: TypeAnnotation

TypeAnnotation fields are

+-------+--------------------------------------------------------+
+_module+ :ref:`rtti::Module <handle_rtti_Module>` ?             +
+-------+--------------------------------------------------------+
+cppName+ :ref:`builtin::das_string <handle_builtin_das_string>` +
+-------+--------------------------------------------------------+
+name   + :ref:`builtin::das_string <handle_builtin_das_string>` +
+-------+--------------------------------------------------------+


to be documented


.. _handle_rtti_TypeInfo:

.. das:attribute:: TypeInfo

TypeInfo fields are

+----------+---------------------------------------------------+
+argTypes  + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>` ??   +
+----------+---------------------------------------------------+
+secondType+ :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>` ?    +
+----------+---------------------------------------------------+
+dimSize   +uint                                               +
+----------+---------------------------------------------------+
+enumType  + :ref:`rtti::EnumInfo <handle_rtti_EnumInfo>` ?    +
+----------+---------------------------------------------------+
+hash      +uint                                               +
+----------+---------------------------------------------------+
+argNames  +string?                                            +
+----------+---------------------------------------------------+
+argCount  +uint                                               +
+----------+---------------------------------------------------+
+basicType + :ref:`rtti::Type <enum_rtti_Type>`                +
+----------+---------------------------------------------------+
+firstType + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>` ?    +
+----------+---------------------------------------------------+
+structType+ :ref:`rtti::StructInfo <handle_rtti_StructInfo>` ?+
+----------+---------------------------------------------------+


TypeInfo properties are

+----------+-----------------------------------------------------------+
+isConst   +bool                                                       +
+----------+-----------------------------------------------------------+
+annotation+ :ref:`rtti::TypeAnnotation <handle_rtti_TypeAnnotation>` ?+
+----------+-----------------------------------------------------------+
+isRawPod  +bool                                                       +
+----------+-----------------------------------------------------------+
+isRef     +bool                                                       +
+----------+-----------------------------------------------------------+
+isImplicit+bool                                                       +
+----------+-----------------------------------------------------------+
+isRefType +bool                                                       +
+----------+-----------------------------------------------------------+
+isPod     +bool                                                       +
+----------+-----------------------------------------------------------+
+isTemp    +bool                                                       +
+----------+-----------------------------------------------------------+
+isRefValue+bool                                                       +
+----------+-----------------------------------------------------------+
+canCopy   +bool                                                       +
+----------+-----------------------------------------------------------+


to be documented


.. _handle_rtti_VarInfo:

.. das:attribute:: VarInfo

VarInfo fields are

+--------------------+---------------------------------------------------------------------------------+
+argTypes            + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>` ??                                 +
+--------------------+---------------------------------------------------------------------------------+
+value               +any                                                                              +
+--------------------+---------------------------------------------------------------------------------+
+secondType          + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>` ?                                  +
+--------------------+---------------------------------------------------------------------------------+
+dimSize             +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+enumType            + :ref:`rtti::EnumInfo <handle_rtti_EnumInfo>` ?                                  +
+--------------------+---------------------------------------------------------------------------------+
+name                +string                                                                           +
+--------------------+---------------------------------------------------------------------------------+
+hash                +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+argNames            +string?                                                                          +
+--------------------+---------------------------------------------------------------------------------+
+argCount            +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+sValue              +string                                                                           +
+--------------------+---------------------------------------------------------------------------------+
+offset              +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+basicType           + :ref:`rtti::Type <enum_rtti_Type>`                                              +
+--------------------+---------------------------------------------------------------------------------+
+firstType           + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>` ?                                  +
+--------------------+---------------------------------------------------------------------------------+
+annotation_arguments+ :ref:`rtti::AnnotationArguments <handle_rtti_AnnotationArguments>`  const? const+
+--------------------+---------------------------------------------------------------------------------+
+structType          + :ref:`rtti::StructInfo <handle_rtti_StructInfo>` ?                              +
+--------------------+---------------------------------------------------------------------------------+


VarInfo properties are

+----------+-----------------------------------------------------------+
+isConst   +bool                                                       +
+----------+-----------------------------------------------------------+
+annotation+ :ref:`rtti::TypeAnnotation <handle_rtti_TypeAnnotation>` ?+
+----------+-----------------------------------------------------------+
+isRawPod  +bool                                                       +
+----------+-----------------------------------------------------------+
+isRef     +bool                                                       +
+----------+-----------------------------------------------------------+
+isImplicit+bool                                                       +
+----------+-----------------------------------------------------------+
+isRefType +bool                                                       +
+----------+-----------------------------------------------------------+
+isPod     +bool                                                       +
+----------+-----------------------------------------------------------+
+isTemp    +bool                                                       +
+----------+-----------------------------------------------------------+
+isRefValue+bool                                                       +
+----------+-----------------------------------------------------------+
+canCopy   +bool                                                       +
+----------+-----------------------------------------------------------+


to be documented


+++++++++++++
Handled types
+++++++++++++

.. _handle_rtti_AnnotationArgumentList:

.. das:attribute:: AnnotationArgumentList

to be documented


.. _handle_rtti_AnnotationArguments:

.. das:attribute:: AnnotationArguments

to be documented


.. _handle_rtti_AnnotationList:

.. das:attribute:: AnnotationList

to be documented


.. _handle_rtti_dasvector`Error:

.. das:attribute:: dasvector`Error

to be documented


++++++++
Generics
++++++++

.. das:function:: class_info ( cl:auto const )  : rtti::StructInfo const?

class_info returns  :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const?



function arguments are

+--+----------+
+cl+auto const+
+--+----------+



to be documented


+++++++++
Functions
+++++++++

.. das:function:: RttiValue_nothing

RttiValue_nothing returns variant<tBool:bool;tInt:int;tUInt:uint;tInt64:int64;tUInt64:uint64;tFloat:float;tDouble:double;tString:string;nothing:any>




to be documented


.. das:function:: arg_names ( info:TypeInfo const )  : iterator<string>

arg_names returns iterator<string>



function arguments are

+----+----------------------------------------------------+
+info+ :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const+
+----+----------------------------------------------------+



to be documented


.. das:function:: arg_names ( info:VarInfo const )  : iterator<string>

arg_names returns iterator<string>



function arguments are

+----+--------------------------------------------------+
+info+ :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const+
+----+--------------------------------------------------+



to be documented


.. das:function:: arg_types ( info:TypeInfo const )  : iterator<rtti::TypeInfo const&>

arg_types returns iterator< :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const&>



function arguments are

+----+----------------------------------------------------+
+info+ :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const+
+----+----------------------------------------------------+



to be documented


.. das:function:: arg_types ( info:VarInfo const )  : iterator<rtti::TypeInfo const&>

arg_types returns iterator< :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const&>



function arguments are

+----+--------------------------------------------------+
+info+ :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const+
+----+--------------------------------------------------+



to be documented


.. das:function:: basic_struct_for_each_field ( arg0:BasicStructureAnnotation const implicit; arg1:block<(string;string;rtti::TypeInfo const;uint):void> const implicit ) 



function arguments are

+----+----------------------------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::BasicStructureAnnotation <handle_rtti_BasicStructureAnnotation>`  const implicit       +
+----+----------------------------------------------------------------------------------------------------+
+arg1+block<(string;string; :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const;uint):void> const implicit+
+----+----------------------------------------------------------------------------------------------------+



to be documented


.. das:function:: builtin_is_same_type ( arg0:rtti::TypeInfo const? const implicit; arg1:rtti::TypeInfo const? const implicit; arg2:RefMatters const; arg3:ConstMatters const; arg4:TemporaryMatters const; arg5:bool const )  : bool

builtin_is_same_type returns bool



function arguments are

+----+--------------------------------------------------------------------+
+arg0+ :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const? const implicit+
+----+--------------------------------------------------------------------+
+arg1+ :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const? const implicit+
+----+--------------------------------------------------------------------+
+arg2+ :ref:`rtti::RefMatters <enum_rtti_RefMatters>`  const              +
+----+--------------------------------------------------------------------+
+arg3+ :ref:`rtti::ConstMatters <enum_rtti_ConstMatters>`  const          +
+----+--------------------------------------------------------------------+
+arg4+ :ref:`rtti::TemporaryMatters <enum_rtti_TemporaryMatters>`  const  +
+----+--------------------------------------------------------------------+
+arg5+bool const                                                          +
+----+--------------------------------------------------------------------+



to be documented


.. das:function:: compile ( arg0:string const; arg1:string const; arg2:block<(bool;smart_ptr<rtti::Program>;das_string const):void> const implicit ) 



function arguments are

+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+arg0+string const                                                                                                                                            +
+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+arg1+string const                                                                                                                                            +
+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+arg2+block<(bool;smart_ptr< :ref:`rtti::Program <handle_rtti_Program>` >; :ref:`builtin::das_string <handle_builtin_das_string>`  const):void> const implicit+
+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+



to be documented


.. das:function:: compile_file ( arg0:string const; arg1:smart_ptr<rtti::FileAccess> const implicit; arg2:block<(bool;smart_ptr<rtti::Program>;das_string const):void> const implicit ) 



function arguments are

+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+arg0+string const                                                                                                                                            +
+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+arg1+smart_ptr< :ref:`rtti::FileAccess <handle_rtti_FileAccess>` > const implicit                                                                            +
+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+arg2+block<(bool;smart_ptr< :ref:`rtti::Program <handle_rtti_Program>` >; :ref:`builtin::das_string <handle_builtin_das_string>`  const):void> const implicit+
+----+--------------------------------------------------------------------------------------------------------------------------------------------------------+



to be documented


.. das:function:: context_for_each_function ( blk:block<(info:rtti::FuncInfo const):void> const ) 



function arguments are

+---+-----------------------------------------------------------------------------+
+blk+block<(info: :ref:`rtti::FuncInfo <handle_rtti_FuncInfo>`  const):void> const+
+---+-----------------------------------------------------------------------------+



to be documented


.. das:function:: context_for_each_variable ( blk:block<(info:rtti::VarInfo const):void> const ) 



function arguments are

+---+---------------------------------------------------------------------------+
+blk+block<(info: :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const):void> const+
+---+---------------------------------------------------------------------------+



to be documented


.. das:function:: each_dim ( info:TypeInfo const )  : iterator<int>

each_dim returns iterator<int>



function arguments are

+----+----------------------------------------------------+
+info+ :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const+
+----+----------------------------------------------------+



to be documented


.. das:function:: each_dim ( info:VarInfo const )  : iterator<int>

each_dim returns iterator<int>



function arguments are

+----+--------------------------------------------------+
+info+ :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const+
+----+--------------------------------------------------+



to be documented


.. das:function:: get_annotation_argument_value ( arg0:AnnotationArgument const implicit )  : RttiValue

get_annotation_argument_value returns  :ref:`RttiValue <alias_RttiValue>` 



function arguments are

+----+---------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::AnnotationArgument <handle_rtti_AnnotationArgument>`  const implicit+
+----+---------------------------------------------------------------------------------+



to be documented


.. das:function:: get_das_type_name ( arg0:Type const )  : string

get_das_type_name returns string



function arguments are

+----+------------------------------------------+
+arg0+ :ref:`rtti::Type <enum_rtti_Type>`  const+
+----+------------------------------------------+



to be documented


.. das:function:: get_dim ( arg0:TypeInfo const implicit; arg1:int const )  : int

get_dim returns int



function arguments are

+----+-------------------------------------------------------------+
+arg0+ :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const implicit+
+----+-------------------------------------------------------------+
+arg1+int const                                                    +
+----+-------------------------------------------------------------+



to be documented


.. das:function:: get_dim ( arg0:VarInfo const implicit; arg1:int const )  : int

get_dim returns int



function arguments are

+----+-----------------------------------------------------------+
+arg0+ :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const implicit+
+----+-----------------------------------------------------------+
+arg1+int const                                                  +
+----+-----------------------------------------------------------+



to be documented


.. das:function:: get_function_info ( arg0:int )  : FuncInfo const&

get_function_info returns  :ref:`rtti::FuncInfo <handle_rtti_FuncInfo>`  const&



function arguments are

+----+---+
+arg0+int+
+----+---+



to be documented


.. das:function:: get_module ( arg0:string const )  : rtti::Module?

get_module returns  :ref:`rtti::Module <handle_rtti_Module>` ?



function arguments are

+----+------------+
+arg0+string const+
+----+------------+



to be documented


.. das:function:: get_this_module ( arg0:smart_ptr<rtti::Program> const implicit )  : rtti::Module?

get_this_module returns  :ref:`rtti::Module <handle_rtti_Module>` ?



function arguments are

+----+----------------------------------------------------------------------+
+arg0+smart_ptr< :ref:`rtti::Program <handle_rtti_Program>` > const implicit+
+----+----------------------------------------------------------------------+



to be documented


.. das:function:: get_total_functions (  )  : int

get_total_functions returns int



function arguments are

+



to be documented


.. das:function:: get_total_variables (  )  : int

get_total_variables returns int



function arguments are

+



to be documented


.. das:function:: get_variable_info ( arg0:int )  : VarInfo const&

get_variable_info returns  :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const&



function arguments are

+----+---+
+arg0+int+
+----+---+



to be documented


.. das:function:: get_variable_value ( arg0:VarInfo const implicit )  : RttiValue

get_variable_value returns  :ref:`RttiValue <alias_RttiValue>` 



function arguments are

+----+-----------------------------------------------------------+
+arg0+ :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const implicit+
+----+-----------------------------------------------------------+



to be documented


.. das:function:: is_compatible_cast ( a:StructInfo const; b:StructInfo const )  : bool

is_compatible_cast returns bool



function arguments are

+-+--------------------------------------------------------+
+a+ :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const+
+-+--------------------------------------------------------+
+b+ :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const+
+-+--------------------------------------------------------+



to be documented


.. das:function:: is_compatible_cast ( arg0:rtti::StructInfo const? const implicit; arg1:rtti::StructInfo const? const implicit )  : bool

is_compatible_cast returns bool



function arguments are

+----+------------------------------------------------------------------------+
+arg0+ :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const? const implicit+
+----+------------------------------------------------------------------------+
+arg1+ :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const? const implicit+
+----+------------------------------------------------------------------------+



to be documented


.. das:function:: is_same_type ( a:TypeInfo const; b:TypeInfo const; refMatters:RefMatters const; constMatters:ConstMatters const; temporaryMatters:TemporaryMatters const; topLevel:bool const )  : bool

is_same_type returns bool



function arguments are

+----------------+------------------------------------------------------------------+
+a               + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const              +
+----------------+------------------------------------------------------------------+
+b               + :ref:`rtti::TypeInfo <handle_rtti_TypeInfo>`  const              +
+----------------+------------------------------------------------------------------+
+refMatters      + :ref:`rtti::RefMatters <enum_rtti_RefMatters>`  const            +
+----------------+------------------------------------------------------------------+
+constMatters    + :ref:`rtti::ConstMatters <enum_rtti_ConstMatters>`  const        +
+----------------+------------------------------------------------------------------+
+temporaryMatters+ :ref:`rtti::TemporaryMatters <enum_rtti_TemporaryMatters>`  const+
+----------------+------------------------------------------------------------------+
+topLevel        +bool const                                                        +
+----------------+------------------------------------------------------------------+



to be documented


.. das:function:: make_file_access ( arg0:string const )  : smart_ptr<rtti::FileAccess>

make_file_access returns smart_ptr< :ref:`rtti::FileAccess <handle_rtti_FileAccess>` >



function arguments are

+----+------------+
+arg0+string const+
+----+------------+



to be documented


.. das:function:: module_for_each_annotation ( arg0:rtti::Module? const implicit; arg1:block<(rtti::Annotation const):void> const implicit ) 



function arguments are

+----+-------------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::Module <handle_rtti_Module>` ? const implicit                           +
+----+-------------------------------------------------------------------------------------+
+arg1+block<( :ref:`rtti::Annotation <handle_rtti_Annotation>`  const):void> const implicit+
+----+-------------------------------------------------------------------------------------+



to be documented


.. das:function:: module_for_each_enumeration ( arg0:rtti::Module? const implicit; arg1:block<(rtti::EnumInfo const):void> const implicit ) 



function arguments are

+----+---------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::Module <handle_rtti_Module>` ? const implicit                       +
+----+---------------------------------------------------------------------------------+
+arg1+block<( :ref:`rtti::EnumInfo <handle_rtti_EnumInfo>`  const):void> const implicit+
+----+---------------------------------------------------------------------------------+



to be documented


.. das:function:: module_for_each_function ( arg0:rtti::Module? const implicit; arg1:block<(rtti::FuncInfo const):void> const implicit ) 



function arguments are

+----+---------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::Module <handle_rtti_Module>` ? const implicit                       +
+----+---------------------------------------------------------------------------------+
+arg1+block<( :ref:`rtti::FuncInfo <handle_rtti_FuncInfo>`  const):void> const implicit+
+----+---------------------------------------------------------------------------------+



to be documented


.. das:function:: module_for_each_generic ( arg0:rtti::Module? const implicit; arg1:block<(rtti::FuncInfo const):void> const implicit ) 



function arguments are

+----+---------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::Module <handle_rtti_Module>` ? const implicit                       +
+----+---------------------------------------------------------------------------------+
+arg1+block<( :ref:`rtti::FuncInfo <handle_rtti_FuncInfo>`  const):void> const implicit+
+----+---------------------------------------------------------------------------------+



to be documented


.. das:function:: module_for_each_global ( arg0:rtti::Module? const implicit; arg1:block<(rtti::VarInfo const):void> const implicit ) 



function arguments are

+----+-------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::Module <handle_rtti_Module>` ? const implicit                     +
+----+-------------------------------------------------------------------------------+
+arg1+block<( :ref:`rtti::VarInfo <handle_rtti_VarInfo>`  const):void> const implicit+
+----+-------------------------------------------------------------------------------+



to be documented


.. das:function:: module_for_each_structure ( arg0:rtti::Module? const implicit; arg1:block<(rtti::StructInfo const):void> const implicit ) 



function arguments are

+----+-------------------------------------------------------------------------------------+
+arg0+ :ref:`rtti::Module <handle_rtti_Module>` ? const implicit                           +
+----+-------------------------------------------------------------------------------------+
+arg1+block<( :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const):void> const implicit+
+----+-------------------------------------------------------------------------------------+



to be documented


.. das:function:: program_for_each_module ( arg0:smart_ptr<rtti::Program> const implicit; arg1:block<(rtti::Module?):void> const implicit ) 



function arguments are

+----+------------------------------------------------------------------------+
+arg0+smart_ptr< :ref:`rtti::Program <handle_rtti_Program>` > const implicit  +
+----+------------------------------------------------------------------------+
+arg1+block<( :ref:`rtti::Module <handle_rtti_Module>` ?):void> const implicit+
+----+------------------------------------------------------------------------+



to be documented


.. das:function:: program_for_each_registered_module ( arg0:block<(rtti::Module?):void> const implicit ) 



function arguments are

+----+------------------------------------------------------------------------+
+arg0+block<( :ref:`rtti::Module <handle_rtti_Module>` ?):void> const implicit+
+----+------------------------------------------------------------------------+



to be documented


.. das:function:: rtti_builtin_structure_for_each_annotation ( arg0:StructInfo const implicit; arg1:block<> const implicit ) 



function arguments are

+----+-----------------------------------------------------------------+
+arg0+ :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const implicit+
+----+-----------------------------------------------------------------+
+arg1+block<> const implicit                                           +
+----+-----------------------------------------------------------------+



to be documented


.. das:function:: set_file_source ( arg0:smart_ptr<rtti::FileAccess> const implicit; arg1:string const; arg2:string const )  : bool

set_file_source returns bool



function arguments are

+----+----------------------------------------------------------------------------+
+arg0+smart_ptr< :ref:`rtti::FileAccess <handle_rtti_FileAccess>` > const implicit+
+----+----------------------------------------------------------------------------+
+arg1+string const                                                                +
+----+----------------------------------------------------------------------------+
+arg2+string const                                                                +
+----+----------------------------------------------------------------------------+



to be documented


.. das:function:: structure_for_each_annotation ( st:StructInfo const; subexpr:block<(ann:rtti::Annotation const;args:rtti::AnnotationArguments const):void> const ) 



function arguments are

+-------+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
+st     + :ref:`rtti::StructInfo <handle_rtti_StructInfo>`  const                                                                                                        +
+-------+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
+subexpr+block<(ann: :ref:`rtti::Annotation <handle_rtti_Annotation>`  const;args: :ref:`rtti::AnnotationArguments <handle_rtti_AnnotationArguments>`  const):void> const+
+-------+----------------------------------------------------------------------------------------------------------------------------------------------------------------+



to be documented


