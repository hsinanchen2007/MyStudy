### 解题思路

滑窗法求解，思路类似 [76.最小覆盖字串](https://leetcode-cn.com/problems/minimum-window-substring/)

[思路](https://leetcode-cn.com/problems/minimum-window-substring/solution/shuang-zhi-zhen-hash-by-hw_wt/)

滑窗 + HASH
52ms 11.1M
--- wangtao HW-2020/3/8

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int left = 0;
        int right = 0;
        unordered_map<char, int> hashp;
        unordered_map<char, int> hash;
        int match = 0;
        for (auto c : p) {
            hashp[c]++;
        }

        while (right < s.size()) {
            if (hashp.count(s[right]) != 0) {
                hash[s[right]]++;
                if (hash[s[right]] == hashp[s[right]]) {
                    match++;
                }
            }
            right++;
            while (match == hashp.size()) {
                if (right - left == p.size()) {
                    ans.push_back(left);
                }
                if (hashp.count(s[left]) != 0) {
                    hash[s[left]]--;
                    if (hash[s[left]] < hashp[s[left]]) {
                        match--;
                    }
                }
                left++;
            }
        }
        return ans;
    }
};
```