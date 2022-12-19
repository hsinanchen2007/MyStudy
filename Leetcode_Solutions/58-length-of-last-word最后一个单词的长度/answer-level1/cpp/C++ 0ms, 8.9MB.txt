### 解题思路
倒着数

![image.png](https://pic.leetcode-cn.com/e0065ba47cc265cb542a5871c5796a950622f67c25fe75d0fb863cbd15968705-image.png)

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length() - 1, now;
        // len 找到从后向前第一个非 ' ' 位
        while(len >= 0 && s[len] == ' ') len --;
        if(len < 0) return 0;
        // now 找到从后向前找到单词的第一位
        now = len;
        while(now >= 0 && s[now] != ' ') now --;
        return len - now;
    }
};
```