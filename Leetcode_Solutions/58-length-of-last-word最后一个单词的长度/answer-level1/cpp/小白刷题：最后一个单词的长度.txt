从最后一个字符遍历，从遍历到的第一个非空格字符开始计数，再遇到空格或遍历完字符串则停止计数

代码：
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int len = s.length() - 1;
        while (len >= 0 && s[len] == ' ')
            len--;
        for (int i = len; i >= 0; i--) {
            if (s[i] != ' ')
                ans++;
            else
                break;
        }
        return ans;
    }
};
```
