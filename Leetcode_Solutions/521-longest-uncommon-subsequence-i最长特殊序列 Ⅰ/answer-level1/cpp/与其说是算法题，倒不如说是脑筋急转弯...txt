求独有的最大非空子集，很显然，任何一个集合的最大非空子集就是它自己..
所以在两个字符串长度不一致的时候，输出最长的那个字符串的长度即可；

两个字符串长度一致的时候又分两种情况，
一是两个字符串相同，因为逻辑上不存在自己有同时自己又没有的东西，所以输出-1；
二是两个字符串不相同，此时的独有最大非空子集依然是自己，直接输出任意一字符串的长度即可。




执行用时 :4 ms, 在所有 C++ 提交中击败了86.65%的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了95.19%的用户

```
class Solution {
public:
    int findLUSlength(string a, string b) {
        
        if(a.length()!=b.length())
            return max(a.length(),b.length());
        
        else{
            
            if(a.compare(b)==0)
                return -1;
            else
                return a.length();
        }
        
        return 0;

    }
};
```
