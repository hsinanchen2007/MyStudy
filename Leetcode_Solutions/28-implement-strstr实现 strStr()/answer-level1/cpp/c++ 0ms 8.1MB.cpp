
![捕获.PNG](https://pic.leetcode-cn.com/d1444212a1c3db719436a1b39dda140dda602297dcfe5441fc5e76643facc218-%E6%8D%95%E8%8E%B7.PNG)


```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(needle.size()>haystack.size())return -1;
        int index=-1,flag=0;
        for(int i=0;i<haystack.size()-needle.size()+1;++i){
            ++index;
            flag=0;
            for(int j=0;j<needle.size();++j){
                if(haystack[j+index]==needle[j]){++flag ;continue ;}
                break;
            }
            if(flag==needle.size()) return index;   
        }
        return -1;
        
    }
};
```