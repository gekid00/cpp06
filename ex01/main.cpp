#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data original;
    original.name = "Alice";
    original.age = 42;
    
    std::cout << "Original Data address: " << &original << std::endl;
    std::cout << "Original Data: name=" << original.name << ", age=" << original.age << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << "Deserialized Data: name=" << deserialized->name << ", age=" << deserialized->age << std::endl;
    
    if (deserialized == &original)
        std::cout << "✓ Pointers are equal!" << std::endl;
    else
        std::cout << "✗ Pointers are NOT equal!" << std::endl;
    
    return (0);
}
