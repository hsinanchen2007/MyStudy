### 解题思路
解法一：中心扩展法，以每一个字符作为中心向两边扩展，就能遍历出每一种回文串并不重复（）

### 代码

```cpp
class Solution {
public:
    int count (string s, int left, int right) {
        int sum = 0;
        while (left >=0 && right < s.size() && s[left--] == s[right++]) {
            sum++;
        }
        return sum;
    }
    int countSubstrings(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += count(s, i, i);
            sum += count(s, i, i+1);
        }
        return sum;
    }
};
```