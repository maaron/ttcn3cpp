
#include "grammar.h"

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

    data = "module SomeModuleName { };";
    assert(TTCN3Module.parse_from(data.begin(), data.end()));
}

int main()
{
    test_grammar();

    return 0;
}