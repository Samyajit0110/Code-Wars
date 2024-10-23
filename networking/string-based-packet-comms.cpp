#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

std::string communicationModule(const std::string &packet)
{
    std::string header = packet.substr(0, 4);
    std::string instruction = packet.substr(4, 4);
    std::string data1_str = packet.substr(8, 4);
    std::string data2_str = packet.substr(12, 4);
    std::string footer = packet.substr(16, 4);
    int data1 = std::stoi(data1_str);
    int data2 = std::stoi(data2_str);
    int result = 0;
    if (instruction == "0F12")
    { // Addition
        result = data1 + data2;
    }
    else if (instruction == "B7A2")
    { // Subtraction
        result = data1 - data2;
    }
    else if (instruction == "C3D9")
    { // Multiplication
        result = data1 * data2;
    }
    else
    {
        return "Invalid instruction";
    }
    if (result < 0)
    {
        result = 0;
    }
    else if (result > 9999)
    {
        result = 9999;
    }
    std::ostringstream response;
    response << header << "FFFF"
             << std::setw(4) << std::setfill('0') << result
             << "0000" << footer;
    return response.str();
}
