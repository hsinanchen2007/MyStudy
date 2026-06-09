### 解题思路
此处撰写解题思路
关键有两点
1、最长回文串的构成，偶数个字符的肯定在回文串中，那奇数个字符串呢，假设字符串是n, 很显然，n - 1 就是偶数了
   所以最长的回文串应该是所有的偶数字符  +   所有奇数字符长度n - 1   , 最后长度加1；加1是从对称的角度来考虑的，   比如aba

2、字符统计计数，使用桶计数，用 map 实现

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> bigMap;

        for (int i = 0; i < s.size(); i++) {
            bigMap[s[i]]++;
        }
        int cnt = 0;
        for (map<char, int>::iterator it = bigMap.begin(); it != bigMap.end(); it++) {
            if (it->second % 2 == 0) {
                cnt += it->second;
            } else {
                cnt += it->second - 1;
            }
        }

        return cnt < s.size() ? cnt + 1 : s.size();
    }
};
```