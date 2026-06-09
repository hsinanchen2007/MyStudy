### 解题思路
这效率也太高了吧哈哈哈哈不过在最坏情况下要循环58*2+length（s)次

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alpha(58);//
        int length=0;
        for (auto c : s)
        {
            alpha[c - 'A']++;
        }
        for (auto cnt : alpha)
        {
            if (cnt % 2 == 1)
            {
                length += 1;
                break;
            }
                
                
        }
        for (auto cnt : alpha)
        {
            if (cnt % 2 == 0)
            {
                length = length + cnt;
            }
            else
                length = length + cnt - 1;

        }
        return length;
    }
};
```