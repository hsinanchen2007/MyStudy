字符串可以排序，那么如果两个字符串相同，则对应位字符均相同。
例如：原字符串 “abcd”
      字符串1 “bacda”  -> 排序后 “a**a**bcd”    
      字符串2 “becda”  -> 排序后 “abcd**e**”
思路比较简单，但是用了排序时间复杂度不够理想，可供参考。

```
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (auto i = 0; i < s.size(); ++i) {
            if (t[i] != s[i]) {
                return t[i];
            }
        }
        return t.back();
    }
};
```
