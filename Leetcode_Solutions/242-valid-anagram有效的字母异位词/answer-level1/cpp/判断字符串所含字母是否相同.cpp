### 解题思路
题目要求是判断两个字符串中所含的字母是否完全相同，即类别和个数都相等。
由于仅仅只有小写字母，就是26个。所以直接判断就好了。

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26);
        for (auto c : s)
        {
            alpha[c - 'a']++;

        }
        for (auto c : t)
        {
            alpha[c - 'a']--;
        }
        for (auto cnt : alpha)
        {
            if (cnt != 0)
            {
                return false;
            }
        }
        return true;

    }
};
```