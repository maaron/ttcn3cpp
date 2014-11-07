#pragma once

// The extensive use of templates causes this "decorated name length too 
// long" warning all over the place.  Since we aren't exporting any of these 
// template instanciations in a library, it is safe to ignore.
#pragma warning( disable : 4503 )

#include <parse\parse.h>

namespace ttcn3 { namespace grammar
{
    using namespace parse;
    using namespace parse::operators;

    parse::never noimp;

    auto a = terminals::u<'a'>();
    auto b = terminals::u<'b'>();
    auto c = terminals::u<'c'>();
    auto d = terminals::u<'d'>();
    auto e = terminals::u<'e'>();
    auto f = terminals::u<'f'>();
    auto g = terminals::u<'g'>();
    auto h = terminals::u<'h'>();
    auto i = terminals::u<'i'>();
    auto j = terminals::u<'j'>();
    auto k = terminals::u<'k'>();
    auto l = terminals::u<'l'>();
    auto m = terminals::u<'m'>();
    auto n = terminals::u<'n'>();
    auto o = terminals::u<'o'>();
    auto p = terminals::u<'p'>();
    auto q = terminals::u<'q'>();
    auto r = terminals::u<'r'>();
    auto s = terminals::u<'s'>();
    auto t = terminals::u<'t'>();
    auto u = terminals::u<'u'>();
    auto v = terminals::u<'v'>();
    auto w = terminals::u<'w'>();
    auto x = terminals::u<'x'>();
    auto y = terminals::u<'y'>();
    auto z = terminals::u<'z'>();
    terminals::u<'A'> A;
    terminals::u<'B'> B;
    terminals::u<'C'> C;
    terminals::u<'D'> D;
    terminals::u<'E'> E;
    terminals::u<'F'> F;
    terminals::u<'G'> G;
    terminals::u<'H'> H;
    terminals::u<'I'> I;
    terminals::u<'J'> J;
    terminals::u<'K'> K;
    terminals::u<'L'> L;
    terminals::u<'M'> M;
    terminals::u<'N'> N;
    terminals::u<'O'> O;
    terminals::u<'P'> P;
    terminals::u<'Q'> Q;
    terminals::u<'R'> R;
    terminals::u<'S'> S;
    terminals::u<'T'> T;
    terminals::u<'U'> U;
    terminals::u<'V'> V;
    terminals::u<'W'> W;
    terminals::u<'X'> X;
    terminals::u<'Y'> Y;
    terminals::u<'Z'> Z;

    terminals::u<'0'> zero;
    terminals::u<'1'> one;
    terminals::u<'2'> two;
    terminals::u<'3'> three;
    terminals::u<'4'> four;
    terminals::u<'5'> five;
    terminals::u<'6'> six;
    terminals::u<'7'> seven;
    terminals::u<'8'> eight;
    terminals::u<'9'> nine;

    terminals::u<';'> semi;
    terminals::u<','> comma;
    terminals::u<'_'> Underscore;
    terminals::u<'"'> dquote;
    terminals::u<'{'> lcurly;
    terminals::u<'}'> rcurly;

    auto ws = +(terminals::space());
    auto lcurly_ws = !ws >> lcurly >> !ws;
    auto rcurly_ws = !ws >> rcurly >> !ws;
    auto semi_ws = !ws >> semi >> !ws;

    auto NonZeroNum = one | two | three | four | five | six | seven | eight | nine;
    auto Num = zero | NonZeroNum;
    auto UpperAlpha = A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z;
    auto LowerAlpha = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;
    auto Alpha = UpperAlpha | LowerAlpha;
    auto AlphaNum = Alpha | Num;
    auto Identifier = Alpha >> *(AlphaNum | Underscore);

    auto FreeText = dquote >> *((dquote >> dquote) | ~dquote) >> dquote;

    auto LanguageKeyword = l | a | n | g | u | a | g | e;
    auto LanguageSpec = LanguageKeyword >> FreeText >> *(comma >> FreeText);
    auto TTCN3ModuleKeyword = m >> o >> d >> u >> l >> e;
    auto ModuleId = Identifier >> !LanguageSpec;
    auto PublicKeyword = p >> u >> b >> l >> i >> c;
    auto PrivateKeyword = p >> r >> i >> v >> a >> t >> e;
    auto FriendKeyword = f >> r >> i >> e >> n >> d;
    auto Visibility = PublicKeyword | PrivateKeyword | FriendKeyword;

    auto TypeDef = noimp;
    auto ConstDef = noimp;
    auto TemplateDef = noimp;
    auto ModuleParDef = noimp;
    auto FunctionDef = noimp;
    auto SignatureDef = noimp;
    auto TestcaseDef = noimp;
    auto AltstepDef = noimp;
    auto ImportDef = noimp;
    auto ExtFunctionDef = noimp;
    auto ExtConstDef = noimp;
    auto GroupDef = noimp;
    auto FriendModuleDef = noimp;
    auto WithStatement = noimp;

    auto ModuleDefinition = ((
        !Visibility >> (
            TypeDef | 
            ConstDef | 
            TemplateDef | 
            ModuleParDef | 
            FunctionDef | 
            SignatureDef | 
            TestcaseDef | 
            AltstepDef | 
            ImportDef | 
            ExtFunctionDef | 
            ExtConstDef)) | 
        (!PublicKeyword >> GroupDef) | 
        (!PrivateKeyword >> FriendModuleDef)) >> !WithStatement;

    auto ModuleControlPart = noimp;

    auto ModuleDefinitionsList = +(ModuleDefinition >> !semi);
    auto TTCN3Module = TTCN3ModuleKeyword >> ws >> ModuleId >> lcurly_ws >> !ModuleDefinitionsList >> !ModuleControlPart >> rcurly_ws >> !WithStatement >> semi_ws;

}}
