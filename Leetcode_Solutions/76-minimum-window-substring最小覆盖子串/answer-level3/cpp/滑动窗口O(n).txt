


### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        unordered_map<char, int> hash;
        
        for (auto &c: t) hash[c]++; // hash存储的是窗口里缺少的字符数
        int cnt = hash.size(); // 窗口里一共的不同的字符种类
        int n = s.size();
  
        for (int l = 0, r = 0, c = 0; r < n; r ++){
            hash[s[r]]--; // 为负数，不需要关心
            if (hash[s[r]] == 0) c++; // 统计 窗口中已经出现的不同字符的忠烈
            while ( c== cnt && hash[s[l]] < 0) hash[s[l++]]++; // 左端点移动；缺少的字符数 小于0，就可以移动
            if (c == cnt) { // 迭代 最优解
                if (ans.empty() || r - l + 1 < ans.size()) ans = s.substr(l, r-l +1);
            }
        }
        return ans;
    }
};
```