#include "MacroParser.hpp"

int main(void)
{
    using namespace MacroParser;
    StringScanner scanner("123+444*2++2");
    TokenStream stream(scanner);
    if (!stream.read_tokens())
    {
        std::printf("scanner failed\n");
    }
    else
    {
        stream.print();
        Parser parser(stream);
        if (!parser.parse())
        {
            std::printf("parser failed\n");
        }
        else
        {
            parser.ast()->print();
        }
    }
    return 0;
}
