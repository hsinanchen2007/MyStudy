### 解题思路
回文即从正着读反着读都相同，即每个字母都为2的倍数，除了中间的那个可以不为2的倍数。
建立一个256大小的int数组，扫一遍字符串统计每个字符的个数，在数一下256个字符中为
奇数的个数，奇数的个数大于1则不能构成回文串。

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int al[256] = {0}, cnt = 0;
        for (int i = 0; i < s.length(); i++) 
            al[s[i]]++;
        for (int i = 0; i < 256; i++){
            if (al[i] & 1)
                cnt++;
        }
        if (cnt > 1)
            return false;
        else
            return true;

    }
};
```