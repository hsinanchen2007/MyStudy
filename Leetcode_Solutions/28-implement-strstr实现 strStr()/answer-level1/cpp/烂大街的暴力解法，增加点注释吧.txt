从头到尾扫描，不放过每一个匹配成功的机会。
### 代码
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        for(int i=0; i<haystack.size()-needle.size()+1; i++){
            int j=0;
            for(; j<needle.size(); j++){
                if(haystack[i+j] != needle[j]){// haystack的下标是在i的基础上增加j
                    break;  // 不等的话直接跳出本循环，然后根据j是否走满来判断是否匹配成功
                }
            }
            if(j == needle.size()) return i;  // 能直接return就不用break了
        }
        return -1;// 前面这么多步骤都没有成功return，走到这一步就只剩下return -1 了。
    }
};
```
