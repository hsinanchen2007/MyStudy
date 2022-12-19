```
class Solution {
public:
    struct Cmp {
        bool operator() (const string& s1, const string s2) const {
            if (s1.empty())
                return true;
            if (s2.empty())
                return false;
            int len1 = s1.size();
            int len2 = s2.size();
            // 循环比较，关键一步
            for (int i = 0; i < len1 + len2; ++i) {
                if (s1[i % len1] == s2[i % len2]) 
                    continue;
                return s1[i % len1] < s2[i % len2];
            }
            return false;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), Cmp());
        string res;
        for (int i = strs.size() - 1; i >= 0; --i) {
            if (res.empty() && strs[i] == "0")
                continue;
            res += strs[i];
        }
        if (res.empty())
            return "0";
        return res;
    }
};
```
