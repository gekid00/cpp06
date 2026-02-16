#include "ScalarConverter.hpp"

static bool isCharInput(const std::string& input)
{
    return (input.length() == 1 && !std::isdigit(input[0]));
}

static bool isPseudoInput(const std::string& input)
{
    return (input == "nan" || input == "nanf"
        || input == "+inf" || input == "-inf"
        || input == "+inff" || input == "-inff"
        || input == "inf" || input == "inff");
}

static bool isValidNumber(const std::string& input)
{
    if (input.empty())
        return false;

    std::string str = input;
    if (str[str.length() - 1] == 'f' && str.length() > 1)
        str = str.substr(0, str.length() - 1);

    char *end;
    strtod(str.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convert(const std::string& input)
{
    double value;

    if (isCharInput(input)) // Check char
    {
        value = static_cast<double>(input[0]);
    }
    else if (isPseudoInput(input)) // Check pseudo
    {
        std::string clean = input;
        if (clean == "nanf" || clean == "+inff" || clean == "-inff" || clean == "inff")
            clean = clean.substr(0, clean.length() - 1);
        value = strtod(clean.c_str(), NULL);
    }
    else if (isValidNumber(input)) // Check number
    {
        std::string clean = input;
        if (clean[clean.length() - 1] == 'f' && clean.length() > 1)
            clean = clean.substr(0, clean.length() - 1);
        value = strtod(clean.c_str(), NULL);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // CHAR
    if (std::isnan(value) || std::isinf(value)
        || value > 127 || value < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    // INT
    if (std::isnan(value) || std::isinf(value)
        || value > static_cast<double>(std::numeric_limits<int>::max())
        || value < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // FLOAT
    if (!std::isinf(value)
        && (value > static_cast<double>(std::numeric_limits<float>::max())
        || value < static_cast<double>(-std::numeric_limits<float>::max())))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(value) << "f" << std::endl;

    // DOUBLE
    std::cout << "double: " << std::fixed << std::setprecision(1)
        << value << std::endl;
}