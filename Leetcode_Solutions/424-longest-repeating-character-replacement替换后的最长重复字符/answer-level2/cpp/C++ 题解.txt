
```C++ []
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int l = 0;
        int m = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            m = max(m, ++counts[s[i]]);
            while (i - l + 1 - m > k) {
                --counts[s[l++]];
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c36f4a51cf1d9d799bda2f1af2bc9c690c8c40a273ea5e70161dcb90c927b403-image.png)
