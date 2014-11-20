
#include "grammar.h"

#include <iostream>
#include <assert.h>

void test_grammar()
{
    using namespace ttcn3::grammar;

    std::string data("0awefiou");
    assert(!Identifier.parse_from(data.begin(), data.end()));

    data = "qwerasdfsdf";
    assert(Identifier.parse_from(data.begin(), data.end()));

    data = " qwer";
    assert(!Identifier.parse_from(data.begin(), data.end()));

    data = "module SomeModuleName { type record mydef {}; type record myotherdef {}; };";
    assert(TTCN3Module.parse_from(data.begin(), data.end()));

    data = "type record mydef {};";
    assert(ModuleDefinition.parse_from(data.begin(), data.end()));
}

void test_ast()
{
    using namespace ttcn3::grammar;

    std::string data = "module SomeModuleName { type record mydef {}; type record myotherdef {}; };";
    auto ast = TTCN3Module.make_ast(data);
    auto valid = TTCN3Module.parse_from(data.begin(), data.end(), ast);
}

int main()
{
    test_grammar();
    test_ast();

    std::cout << "tests passed" << std::endl;

    return 0;
}