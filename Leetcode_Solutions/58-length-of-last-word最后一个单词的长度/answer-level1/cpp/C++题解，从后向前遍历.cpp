# 思路
从字符串末尾开始，向前遍历，变量res记录最后一个的单词，即此时第一个单词的长度，当遇见空格时，如果已经出现了单词，则说明此单词已结束，返回其长度；否则，继续搜索前一个字符。如果遇见的是单词，res加一。

# 代码
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length(), res = 0;
        if(len == 0)
            return 0;

        for(int i = len-1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(res)
                    return res;
            }
            else
                res++;
        }
        
        return res;
    }
};
```
