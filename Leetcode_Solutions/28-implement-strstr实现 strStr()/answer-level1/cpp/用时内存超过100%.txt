### 解题思路
就正常的遍历循环
超过双100%

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenn = needle.size();
        if(lenn == 0 ) return 0;
        int len = haystack.size();
        if(len < lenn) return -1;
        //if(len == 0 && lenn == 0) return 0;
        int i = 0,j=0;
        for( ; i < len - lenn + 1 ; i++){
            if(haystack[i] == needle[0]){
                while(j < lenn && needle[j] == haystack[i] && i < len){
                    j++;
                    i++;
}
                if(j == lenn)
                     return i-lenn;
                else{
                    i = i - j;
                    j = 0;
                }
            }
        }
        return -1;
    }
};
```