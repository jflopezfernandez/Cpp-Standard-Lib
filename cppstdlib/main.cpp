
#include <algorithm>
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

int main(int argc, char *argv[])
{
    const std::string data = "<Person>\n"
                             "    <FirstName>John</FirstName>\n"
                             "    <LastName>Meier</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>Kobe</FirstName>\n"
                             "    <LastName>Bryant</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>Charles</FirstName>\n"
                             "    <LastName>Barkley</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>John</FirstName>\n"
                             "    <LastName>Cena</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>Jacob</FirstName>\n"
                             "    <LastName>Jingleheimer-Schmidtt</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>John</FirstName>\n"
                             "    <LastName>Kelly</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>James</FirstName>\n"
                             "    <LastName>Mattis</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>Paul</FirstName>\n"
                             "    <LastName>Rudd</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>Jimmy</FirstName>\n"
                             "    <LastName>Kimmel</LastName>\n"
                             "</Person>\n"
                             "<Person>\n"
                             "    <FirstName>Jake</FirstName>\n"
                             "    <LastName>Paul</LastName>\n"
                             "</Person>\n";

    std::regex tagRegex("<(.*)>(.*)</(\\1)>");

    // Use a std::regex_iterator to process each matched substring as element in an algorithm
    std::sregex_iterator beg(data.cbegin(), data.cend(), tagRegex);
    std::sregex_iterator end;

    for_each (beg, end, [](const std::smatch& match) {
        std::cout << "Match: " << match.str()  << "\n";
        std::cout << "  Tag: " << match.str(1) << "\n";
        std::cout << "Value: " << match.str(2) << "\n\n";
    });
}
