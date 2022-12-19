# 思路
1. 从左往右遍历字符串
2. 记录字母数量(遇到字符串重新计数)
3. 防止尾部空格：再添加一个变量记录上上个状态


```
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;

        int count = 0;
        int result = 0;  // 防止尾部空格
        for(char chr : s)
        {
            if(chr == ' ')
            {
                result = count ? count : result;  // 记录最后一个单词
                count = 0;
                continue;
            }
            count++;
        }

        return count ? count : result;
    }
};
```
