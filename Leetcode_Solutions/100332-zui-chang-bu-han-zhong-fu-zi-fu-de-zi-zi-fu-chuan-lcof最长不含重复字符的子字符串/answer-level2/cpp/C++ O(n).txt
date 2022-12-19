```c++
class Solution {
public:
    int lengthOfLongestSubstring(const std::string s) {
        int ans = 0, last = -1;
        std::vector<int> vec(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            ans = std::max(ans, i - std::max(last, vec[s[i]]));
            last = std::max(last, vec[s[i]]);
            vec[s[i]] = i;
        }
        return ans;
    }
};
```