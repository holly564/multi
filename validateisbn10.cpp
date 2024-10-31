#include <iostream>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <string_view>
#include  <array>
#include <string>


bool validate_isbn_10(std::string_view isbn)
{
   auto valid = false;

   if (isbn.size() == 10 &&
       std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10)
   {
      auto w = 10;
      auto sum = std::accumulate(
         std::begin(isbn), std::end(isbn), 0,
         [&w](int const total, char const c) {
            return total + w-- * (c - '0'); });

     valid = !(sum % 11);
   }
   return valid;
}

int main()
{
    std::string isbstr = "3161484100";
    std::string_view isbstr_v(isbstr);
    std::cout<<"validate '3-16-148410-0' is " << validate_isbn_10(isbstr)<< "\n";
    
    std::array<std::string_view, 3> isbn_va {"0-596-52068", "1770864047", "0-439-02348-3"};
    for (const auto& isbn : isbn_va)
        std::cout<<validate_isbn_10(isbn) << "\n";
    std::cout << '\n';

    return 0;
}
