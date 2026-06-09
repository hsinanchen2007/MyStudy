```
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if(nums.empty()) return "";
        string res;
        vector<string> strs;
        for(int num : nums) strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), [](string s1, string s2) {return s1 + s2 < s2 + s1;});
        for(string str : strs) res += str;
        return res;
    }
};
```
