### 解题思路
使用一层循环枚举子串起点并用substr函数取子串比较，再加上特判即可。

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0||haystack==needle)
            return 0;
        if(haystack.size()==0||haystack.size()<needle.size())
            return -1;
        string t;
        for(int i=0;i<=haystack.size()-needle.size();i++)
        {
            t=haystack.substr(i,needle.size());
            if(t==needle)
                return i;
        }
        return -1;
    }
};
```