本题得到的启发是：对于多层级的分类可以用以下方式分别表示：
```C++
vector<pair<int, string>> rep{{pow(10, 9), " Billion"}, {pow(10, 6), " Million"}, {pow(10, 3), " Thousand"}, {pow(10, 2), " Hundred"}};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
```
以及如何处理字符和字符之间的空格