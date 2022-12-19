### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 手写Sunday算法
        int lenneedle = needle.size();
        if(lenneedle==0){
            return 0;
        }
        int lenhay = haystack.size();
        int start = 0; // 字符串匹配起点
        while(start <= lenhay - lenneedle){
            // 首先从前向后匹配到不匹配为止
            for(int i=0;i<lenneedle;i++){
                // 若匹配失败，
                if(needle[i]!=haystack[i+start]){
                    // 则考虑末尾+1位的字符是否在模式串中，倒向
                    for(int j=lenneedle-1;j>=0;j--){
                        // 若在，则移动至与该字符匹配，倒向
                        if(needle[j]==haystack[lenneedle+start]){
                            start += lenneedle-j;
                            break;
                        }
                        else if(j==0){ // 该字符不在模式串中，则后移start至该字符的向后一位
                            start += lenneedle+1;
                        }
                    }
                    break;
                }
                else if(i==lenneedle-1){ // 匹配成功
                    return start;
                }
            }
        }
        return -1;

    }
};
```