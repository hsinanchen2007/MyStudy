### 解题思路
![1584666147(1).jpg](https://pic.leetcode-cn.com/05019b78470910ad60ee4b34db4887866b3378514e9534ccf034c8993f77fee5-1584666147\(1\).jpg)

### 代码

```cpp

class Solution {
public:
    int longestPalindrome(string s) {
        int str[58] = {0};
        for(auto c : s)
        {
            str[c-'A']++;
        }
        int cnt = 0;
        for(int i = 0; i < 58; ++i)
        {
            if(str[i] > 1)
                cnt += str[i] / 2 * 2;
        }
        if(cnt < s.size())
            cnt++;
        return cnt;
    }
};
```