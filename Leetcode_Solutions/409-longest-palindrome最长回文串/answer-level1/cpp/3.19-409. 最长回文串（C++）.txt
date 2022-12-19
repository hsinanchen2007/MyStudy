### 解题思路
注意：构造最长的回文串，不是最长的回文子串

成双成对+一个单身狗

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for (char cur : s) {
            map[cur]++;
        }
        int res = 0;
        int order = 0;
        for(auto pair : map) {
            if (pair.second % 2 == 1) {
                order++;
            }
            res += pair.second / 2 * 2;      
        }
        if (order > 0) {
            res++;
        }
        return res;
    }
};
```