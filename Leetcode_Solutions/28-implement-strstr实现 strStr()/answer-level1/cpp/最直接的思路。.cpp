### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1=haystack.size(),len2=needle.size();
        for(int i=0;i<len1-len2+1;i++){
            bool flag=true;
            for(int j=0;j<len2;j++){
                if(haystack[j+i]!=needle[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
                break;
            }
        }
        return -1;
    }
};
```