### 解题思路
判断当前s[i]字符对应值与s[i + 1]字符对应值大小关系：
（1）若小于则ans -= t[s[i]];
（2）否则 ans += t[s[i]];

附：跑起来不是特别快，但是胜在思路清晰，代码量比较少。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> t;
        t['I'] = 1, t['V'] = 5;
        t['X'] = 10, t['L'] = 50;
        t['C'] = 100, t['D'] = 500;
        t['M'] = 1000;
        int ans = 0;
        int n = s.size();
        for (int  i = 0; i < n - 1; i++) {
            if (t[s[i]] < t[s[i + 1]]) {
                ans -= t[s[i]];
            } else {
                ans += t[s[i]];
            }
        }
        ans += t[s[n - 1]];
        return ans;    
    }
};
```