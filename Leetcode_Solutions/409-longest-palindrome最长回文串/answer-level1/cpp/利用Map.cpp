![捕获.PNG](https://pic.leetcode-cn.com/4dc6f18b687820df9f902a8d67265e6efcb5290a7eddb7c98c45ca5a7015ea0f-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> my_map;
        for(auto ch:s)
            ++my_map[ch];
        int count=0;
        bool flag=false;
        for(auto iter=my_map.cbegin();iter!=my_map.cend();++iter){
            if(iter->second>=2)
                count+=(iter->second/2)*2;
            if(iter->second%2!=0)
                flag= true;
        }
        if(flag) return count+1;
        return count;
    }
};
```
