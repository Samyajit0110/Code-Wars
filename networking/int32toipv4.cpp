#include <iostream>
#include <string>
using namespace std;

string uint32_to_string(uint32_t ip)
{
    int octet1 = ip >> 24 & 0xFF;
    int octet2 = ip >> 16 & 0xFF;
    int octet3 = ip >> 8 & 0xFF;
    int octet4 = ip & 0xFF;
    string ipv4;
    ipv4 += to_string(octet1) + "." + to_string(octet2) + "." + to_string(octet3) + "." + to_string(octet4);
    return ipv4;
}

int main()
{
    cout << uint32_to_string(2149583361);
}
