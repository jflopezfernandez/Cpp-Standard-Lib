
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include <Catch/catch.hpp>

#include <boost/program_options.hpp>

#include <gsl/gsl>

inline std::string Found(const bool result)
{
    return ((result) ? "Found" : "Not found");
}


int main(int argc, char *argv[])
{
    const std::string defaultRegex { "\\(?\\d{3}[-\\) ]+\\d{3}[- ]?\\d{4}" };

    std::regex phoneNumberRegex;

    if (argc == 1)
    {
        std::cout << "[No regex supplied, using default]: /" << defaultRegex << "/\n";

        phoneNumberRegex = defaultRegex;
    } else
    {
        phoneNumberRegex = std::regex { argv[1] };
    }

    std::vector<std::string> phoneNumbers = {
        "813-555-0123",
        "012 344 0123",
        "(813) 234-0211",
        "(124)888-1002"
    };

    for (auto& phoneNumber : phoneNumbers)
    {
        std::cout << "[" << phoneNumber << "]: " << std::boolalpha << std::regex_match(phoneNumber, phoneNumberRegex) << "\n";
    }

    

    //std::regex_match("XML tag: <tag-name>the value</tag-name>.", m, std::regex("<(.*)>(.*)</(\\1)>"));
}