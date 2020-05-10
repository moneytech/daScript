#include "daScript/misc/platform.h"

#include "module_builtin_rtti.h"

#include "daScript/simulate/simulate_visit_op.h"
#include "daScript/ast/ast_policy_types.h"
#include "daScript/ast/ast_expressions.h"
#include "daScript/simulate/aot_builtin_ast.h"

using namespace das;

MAKE_TYPE_FACTORY(TypeDecl,TypeDecl)
MAKE_TYPE_FACTORY(FieldDeclaration, Structure::FieldDeclaration)
MAKE_TYPE_FACTORY(Structure,Structure)
MAKE_TYPE_FACTORY(Enumeration,Enumeration)
MAKE_TYPE_FACTORY(Expression,Expression)

namespace das {

    TypeDeclPtr makeExprGenFlagsFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprGenFlags";
        ft->argNames = { "alwaysSafe", "generated" };
        return ft;
    }

    TypeDeclPtr makeExprFlagsFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprFlags";
        ft->argNames = { "constexpression", "noSideEffects", "noNativeSideEffects" };
        return ft;
    }

    TypeDeclPtr makeExprPrintFlagsFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "ExprPrintFlags";
        ft->argNames = { "topLevel", "argLevel", "bottomLevel" };
        return ft;
    }

    template <typename EXPR>
    struct AstExprAnnotation : ManagedStructureAnnotation <EXPR> {
        AstExprAnnotation(const string & en, ModuleLibrary & ml)
            : ManagedStructureAnnotation<EXPR> (en, ml) {
        }
        void init() {
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(type)>("type");
            addFieldEx ( "genFlags", "genFlags", offsetof(Expression, genFlags), makeExprGenFlagsFlags() );
            addFieldEx ( "flags", "flags", offsetof(Expression, flags), makeExprFlagsFlags() );
            addFieldEx ( "printFlags", "printFlags", offsetof(Expression, printFlags), makeExprPrintFlagsFlags() );
        }
    };

    struct AstExpressionAnnotation : AstExprAnnotation<Expression> {
        AstExpressionAnnotation(ModuleLibrary & ml)
            :  AstExprAnnotation<Expression> ("Expression", ml) {
        }
    };

    struct AstEnumerationAnnotation : ManagedStructureAnnotation <Enumeration> {
        AstEnumerationAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("Enumeration", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(cppName)>("cppName");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(list)>("list");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
            addField<DAS_BIND_MANAGED_FIELD(external)>("external");
            addField<DAS_BIND_MANAGED_FIELD(baseType)>("baseType");
        }
    };

    TypeDeclPtr makeTypeDeclFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "TypeDeclFlags";
        ft->argNames = { "ref", "constant", "temporary", "implicit",
            "removeRef", "removeConstant", "removeDim",
            "removeTemporary", "explicitConst", "aotAlias", "smartPtr" };
        return ft;
    }

    struct AstTypeDeclAnnnotation : ManagedStructureAnnotation <TypeDecl> {
        AstTypeDeclAnnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("TypeDecl", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(baseType)>("baseType");
            addField<DAS_BIND_MANAGED_FIELD(structType)>("structType");
            addField<DAS_BIND_MANAGED_FIELD(enumType)>("enumType");
            addField<DAS_BIND_MANAGED_FIELD(annotation)>("annotation");
            addField<DAS_BIND_MANAGED_FIELD(firstType)>("firstType");
            addField<DAS_BIND_MANAGED_FIELD(secondType)>("secondType");
            addField<DAS_BIND_MANAGED_FIELD(argTypes)>("argTypes");
            addField<DAS_BIND_MANAGED_FIELD(argNames)>("argNames");
            addField<DAS_BIND_MANAGED_FIELD(dim)>("dim");
            addField<DAS_BIND_MANAGED_FIELD(dimExpr)>("dimExpr");
            addFieldEx ( "flags", "flags", offsetof(TypeDecl, flags), makeTypeDeclFlags() );
            addField<DAS_BIND_MANAGED_FIELD(alias)>("alias");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
        }
    };

    TypeDeclPtr makeFieldDeclarationFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "FieldDeclarationFlags";
        ft->argNames = { "moveSemantic", "parentType", "capturedConstant", "generated" };
        return ft;
    }

    struct AstFieldDeclarationAnnotation : ManagedStructureAnnotation<Structure::FieldDeclaration> {
        AstFieldDeclarationAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("FieldDeclaration", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
            addField<DAS_BIND_MANAGED_FIELD(type)>("type");
            addField<DAS_BIND_MANAGED_FIELD(init)>("init");
            addField<DAS_BIND_MANAGED_FIELD(annotation)>("annotation");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(offset)>("offset");
            addFieldEx ( "flags", "flags", offsetof(Structure::FieldDeclaration, flags), makeFieldDeclarationFlags() );
        }
    };

    TypeDeclPtr makeStructureFlags() {
        auto ft = make_smart<TypeDecl>(Type::tBitfield);
        ft->alias = "StructureFlags";
        ft->argNames = { "isClass", "genCtor", "cppLayout", "cppLayoutNotPod", "generated" };
        return ft;
    }

    struct AstStructureAnnotation : ManagedStructureAnnotation<Structure> {
        AstStructureAnnotation(ModuleLibrary & ml)
            : ManagedStructureAnnotation ("Structure", ml) {
        }
        void init () {
            addField<DAS_BIND_MANAGED_FIELD(name)>("name");
             addField<DAS_BIND_MANAGED_FIELD(fields)>("fields");
            addField<DAS_BIND_MANAGED_FIELD(at)>("at");
            addField<DAS_BIND_MANAGED_FIELD(module)>("module");
            addField<DAS_BIND_MANAGED_FIELD(parent)>("parent");
            // addField<DAS_BIND_MANAGED_FIELD(annotations)>("annotations");
            addFieldEx ( "flags", "flags", offsetof(Structure, flags), makeStructureFlags() );
        }
    };

    struct SimNode_AstGetTypeDecl : SimNode_CallBase {
        DAS_PTR_NODE;
        SimNode_AstGetTypeDecl ( const LineInfo & at, const TypeDeclPtr & d )
            : SimNode_CallBase(at) {
            typeExpr = d.get();
        }
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            V_OP(RttiGetTypeDecl);
            V_ARG(typeExpr->getMangledName().c_str());
            V_END();
        }
        __forceinline char * compute(Context &) {
            DAS_PROFILE_NODE
            return (char *) typeExpr;
        }
        TypeDecl *  typeExpr;   // requires RTTI
    };

    struct AstTypeDeclMacro : TypeInfoMacro {
        AstTypeDeclMacro() : TypeInfoMacro("ast_typedecl") {}
        virtual TypeDeclPtr getAstType ( ModuleLibrary & lib, const ExpressionPtr &, string & ) override {
            return typeFactory<const TypeDecl *>::make(lib);
        }
        virtual SimNode * simluate ( Context * context, const ExpressionPtr & expr, string & ) {
            auto exprTypeInfo = static_pointer_cast<ExprTypeInfo>(expr);
            return context->code->makeNode<SimNode_AstGetTypeDecl>(expr->at, exprTypeInfo->typeexpr);
        }
        virtual bool noAot ( const ExpressionPtr & ) const override {
            return true;
        }
    };

    /*
        class Function : public ptr_ref_count {
    public:
        AnnotationList      annotations;
        string              name;
        vector<VariablePtr> arguments;
        TypeDeclPtr         result;
        ExpressionPtr       body;
        int                 index = -1;
        uint32_t            totalStackSize = 0;
        int32_t             totalGenLabel = 0;
        LineInfo            at, atDecl;
        Module *            module = nullptr;
        das_set<Function *>     useFunctions;
        das_set<Variable *>     useGlobalVariables;
        union {
            struct {
                bool    builtIn : 1;
                bool    policyBased : 1;
                bool    callBased : 1;
                bool    interopFn : 1;
                bool    hasReturn: 1;
                bool    copyOnReturn : 1;
                bool    moveOnReturn : 1;
                bool    exports : 1;
                bool    init : 1;
                bool    addr : 1;
                bool    used : 1;
                bool    fastCall : 1;
                bool    knownSideEffects : 1;
                bool    hasToRunAtCompileTime : 1;
                bool    unsafe : 1;
                bool    unsafeOperation : 1;
                bool    unsafeDeref : 1;
                bool    hasMakeBlock : 1;
                bool    aotNeedPrologue : 1;
                bool    noAot : 1;
                bool    aotHybrid : 1;
                bool    aotTemplate : 1;
                bool    generated : 1;
                bool    privateFunction : 1;
                bool    generator : 1;
                bool    lambda : 1;
            };
            uint32_t flags = 0;
        };
        uint32_t    sideEffectFlags = 0;
        struct InferHistory {
            LineInfo    at;
            Function *  func = nullptr;
            InferHistory() = default;
            InferHistory(const LineInfo & a, const FunctionPtr & p) : at(a), func(p.get()) {}
        };
        vector<InferHistory> inferStack;
        Function * fromGeneric = nullptr;
        uint64_t hash = 0;
        uint64_t aotHash = 0;
    };
    */

    #include "ast.das.inc"

    char * ast_describe ( smart_ptr_raw<TypeDecl> t, bool d_extra, bool d_contracts, bool d_module, Context * context ) {
        return context->stringHeap.allocateString(t->describe(
            d_extra ? TypeDecl::DescribeExtra::yes : TypeDecl::DescribeExtra::no,
            d_contracts ? TypeDecl::DescribeContracts::yes : TypeDecl::DescribeContracts::no,
            d_module ? TypeDecl::DescribeModule::yes : TypeDecl::DescribeModule::no));
    }

    class Module_Ast : public Module {
    public:
        template <typename RecAnn>
        void addRecAnnotation ( ModuleLibrary & lib ) {
            auto rec = make_smart<RecAnn>(lib);
            addAnnotation(rec);
            initRecAnnotation(rec, lib);
        }
        Module_Ast() : Module("ast") {
            ModuleLibrary lib;
            lib.addModule(this);
            lib.addBuiltInModule();
            lib.addModule(Module::require("rtti"));
            // THE MAGNIFICENT TWO
            addTypeInfoMacro(make_smart<AstTypeDeclMacro>());
            // FLAGS?
            addAlias(makeTypeDeclFlags());
            addAlias(makeFieldDeclarationFlags());
            addAlias(makeStructureFlags());
            addAlias(makeExprGenFlagsFlags());
            addAlias(makeExprFlagsFlags());
            addAlias(makeExprPrintFlagsFlags());
            // AST TYPES
            auto exa = make_smart<AstExpressionAnnotation>(lib);
            addAnnotation(exa);
            auto tda = make_smart<AstTypeDeclAnnnotation>(lib);
            addAnnotation(tda);
            auto sta = make_smart<AstStructureAnnotation>(lib);
            addAnnotation(sta);
            auto fta = make_smart<AstFieldDeclarationAnnotation>(lib);
            addAnnotation(fta);
            auto ena = make_smart<AstEnumerationAnnotation>(lib);
            addAnnotation(ena);
            initRecAnnotation(tda, lib);
            initRecAnnotation(sta, lib);
            initRecAnnotation(fta, lib);
            initRecAnnotation(ena, lib);
            initRecAnnotation(exa, lib);
            // helper functions
            addExtern<DAS_BIND_FUN(ast_describe)>(*this, lib,  "ast_describe",
                SideEffects::none, "ast_describe");
            // add builtin module
            compileBuiltinModule("ast.das",ast_das,sizeof(ast_das));
            // lets make sure its all aot ready
            // verifyAotReady();
        }
        virtual ModuleAotType aotRequire ( TextWriter & tw ) const override {
            tw << "#include \"daScript/simulate/aot_builtin_ast.h\"\n";
            return ModuleAotType::hybrid;
        }
    };
}

REGISTER_MODULE_IN_NAMESPACE(Module_Ast,das);
