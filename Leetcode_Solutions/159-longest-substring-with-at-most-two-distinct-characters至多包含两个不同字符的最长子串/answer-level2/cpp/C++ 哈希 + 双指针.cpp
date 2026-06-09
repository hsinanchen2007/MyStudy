```C++ []
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> indices;
        int res = 0;
        int k = 0;
        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            k += indices.count(s[i]) == 0 || indices[s[i]] < l;
            if (k > 2) {
                while (indices[s[l]] > l) ++l;
                ++l;
                --k;
            }
            indices[s[i]] = i;
            res = max(res, i - l + 1);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/6f8683a84c82722e87acb81637132a182b02774f918ab316248b79f30153a45b-image.png)
