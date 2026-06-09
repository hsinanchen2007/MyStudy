![捕获.PNG](https://pic.leetcode-cn.com/25aba95fba34d6114e367c1f0ad141988cecb43070b55e5435245ca862eb981c-%E6%8D%95%E8%8E%B7.PNG)
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(haystack.size()<needle.size()) return -1;
        string::iterator first=haystack.begin(),second=first+(needle.size()-1);
        while(second!=haystack.end()){
            string temp(first,second+1);
            if(temp==needle){
                return first-haystack.begin();
            }
            ++first;++second;
        }
        return -1;

    }
};
```
