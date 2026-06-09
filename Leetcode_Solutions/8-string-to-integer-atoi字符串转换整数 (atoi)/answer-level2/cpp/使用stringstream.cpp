使用stringstream来读取数字
```c++
class Solution {
public:
    int myAtoi(string str) {
        while(*str.begin() == ' ') str.erase(str.begin());
        if(str == "") return 0;
        stringstream ss;
        ss<<str;
        int n;
        ss>>n;
        return n;
    }
};
```