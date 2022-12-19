我认为这一题看英文discuss中的滑动窗口模板总结比较好，其中有最大最小应该怎么写，非常秒杀这类题
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char, int> hash;
        for (char tc: t) hash[tc] ++;
        int l = 0, r = 0, counter = hash.size();
        string ans;
        int maxsize = INT_MAX;
        while (r < s.size()) {
            if (hash[s[r ++]] -- == 1) counter --;
            if (counter == 0) {
                while (counter == 0) {
                    if (r - l < maxsize) {
                        ans = s.substr(l, r - l);
                        maxsize = r - l;
                    }
                    if (hash[s[l ++]] ++ == 0) counter ++;
                }
            }
        }
        return ans;
    }
};
```