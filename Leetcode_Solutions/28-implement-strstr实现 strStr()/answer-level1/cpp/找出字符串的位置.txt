### 解题思路
双指针解法内存消耗比较小,但是效率比较低,下面学习一下KMP再来做一遍

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }else if(haystack == "" || haystack.length()<needle.length()){
            return  -1;
        }
        int j=0;
        for(int i=0;i<haystack.length();i++){
            for(j=0;j<needle.length();j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j==needle.length()){
                return i;
            }
        }
        return -1;

    }
};
```