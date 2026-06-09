思路简单：N可由N-2的结果两端加对称字符直接得到
代码如下：
```
class Solution {
public:
    vector<char> A{'1', '0', '8'};
    map<char, char> B{{'6', '9'}, {'9', '6'}};
    vector<string> dfs(int n) {
        vector<string> res;
        if (n == 0) return {""};
        if (n == 1) return {"1", "0", "8"};
        for (auto& s : dfs(n - 2)) {
            for (auto& c : A) res.push_back(c + s + c);
            for (auto& p : B) res.push_back(p.first + s + p.second);
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        if (n == 1) return {"1", "0", "8"};
        auto strs = dfs(n);
        vector<string> res;
        for(auto& s : strs) {
            if (s[0] != '0')
                res.push_back(s);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d7898bb8b2a5739499f39caf53b81d3b805600a66bf8ac2933b78f51751964d1-image.png)
