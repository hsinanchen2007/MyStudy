### 解题思路
从尾部开始遍历，遇到第一个非空格在执行计数任务，直到下一次空格的出现在跳出循环。

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i ) {
            if (s[i] != ' ')
                ans ++;
            if (ans != 0 && s[i] == ' ')
                break;
        }
        if (ans != 0) 
            return ans;
        else 
            return 0;
    }
};
```