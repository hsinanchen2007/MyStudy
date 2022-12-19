使用C++标准字符串IO库<sstream>中的istringstream函数
```
class Solution {
public:
    int myAtoi(string str) {
        int digit=0;
        istringstream is(str);
        is>>digit;
        return digit;
    }
};
```
