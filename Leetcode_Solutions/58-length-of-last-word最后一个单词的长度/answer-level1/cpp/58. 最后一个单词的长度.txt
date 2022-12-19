不知道为什么测试用例"a"不通过。。。。。。。。
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i = s.length() - 1;
        while(i >= 0 && s[i] != ' ')
            i--;
        return s.length() - 1 - i;
    }
};
```
