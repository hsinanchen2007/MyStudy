### 解题思路
KMP 算法
1. 生成next数组
2. 根据next数组匹配

### 代码

```cpp
class Solution {
public:
    vector<int> getnext(string& needle){
        vector<int> next(needle.size());
        int i=0; 
        int j=-1;
         next[0] = -1;
         int len = needle.length();
        while(i<len-1){
            if(j==-1 || needle[i] == needle[j]){
                j++;
                i++;
                if(needle[i] == needle[j]){
                    next[i] = next[j];
                }else{
                    next[i] = j;
                }
            }else{
                j = next[j];
            }
        }
        return next;
    };

    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        if(haystack.empty()){
            return -1;
        }
        vector<int> next = getnext(needle);
      
        int j=0;
        int i=0;
        while(i<haystack.length()){
            if(j==-1||haystack[i] == needle[j] ){
                i++;
                j++;
                if(j==needle.length()){
                    return i-j;
                }
            }else{
                j = next[j];
            }
        }
        return -1;
    }
};
```