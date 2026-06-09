```
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if ( needle.empty() ) return 0;
        int count = 0;
        string::size_type idx; //这个声明很重要, 不能用别的声明方式
        idx = haystack.find(needle);
        if ( idx == string::npos ) // 找不到的情况
            return -1;
        
        int target = haystack.find( needle ); //找得到的情况下返回值是int类型的！
        
        for (int i = 0; i < target; i++) {
            ++count;
        }
        
        return count;
        
    }
    
};
```
