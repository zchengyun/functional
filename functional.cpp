#include <iostream>
#include <functional>//函数

std::string print(std::string str) {
    return str;
}

struct Struct
{
public:

    std::string print(std::string str) {
        return str;
    }
};
int main()
{
    std::function<std::string(std::string)> handle1 = print;
    std::cout << handle1("good\n");

    auto padd = [](int a, int b)->std::string {return "good1\n"; };
    std::function<std::string(int a, int b)> handle2 = padd;
    std::cout<<handle2(1,2);

    std::function<std::string(std::string)> handle3 = std::bind(print, "good2\n");
    std::cout<<handle3("");

    std::shared_ptr<Struct> struct1 = std::make_shared<Struct>();
    std::function<std::string(std::string)> handle4 = std::bind(&Struct::print, struct1,"good3\n");
    std::cout << handle4("");

}

