![Screen Shot 2020-04-01 at 1.34.37 PM.png](https://pic.leetcode-cn.com/474e3df96d6cea7a5244c6365d4a4a38dffa36a62ab9f4d2072ac65bee52ef8a-Screen%20Shot%202020-04-01%20at%201.34.37%20PM.png)


```c++
class Solution {
public:
    int longestSubstring(string s, int k) {
        //递归出口
        if (s.size() < k) return 0;
        unordered_map<char, int> dict;
        for (char c : s) dict[c]++;
        int total = 0;
        for (auto item : dict) {
            if (item.second >= k) total += item.second;
        }
        if (total == s.size()) return total;
        //递归求解
        int left = -1, right = -1;
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            if (left == -1 && dict[s[i]] >= k) left = i;
            if (left != -1 && right == -1 && dict[s[i]] < k) right = i;
            if (left != -1 && right != -1 && right >= left) {
                res.push_back(longestSubstring(s.substr(left, right-left), k));
                left = -1;
                right = -1;
            }
        }
        if (left != -1 && right == -1) 
            res.push_back(longestSubstring(s.substr(left, s.size()-left), k));
        //所有字问题的最大值
        int ans = 0;
        for (int num : res) 
            ans = max(ans, num);
        return ans;
    }
};
```
