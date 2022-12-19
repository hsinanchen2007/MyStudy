### 解题思路

因为每两个字符可能用多种规则得到多种结果，所以可以用DFS回溯。

执行用时 :4 ms, 在所有 C++ 提交中击败了98.98% 的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了56.25%的用户

### 代码

```cpp
class Solution {
private:
    unordered_map<string, vector<char>> dict;
public:
    void init(string bottom, vector<string>& allowed) {
        for(string& rule: allowed) {
            dict[rule.substr(0, 2)].push_back(rule[2]);
        }
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        init(bottom, allowed);
        return dfs(bottom, "", 0);
    }
    
    bool dfs(string bottom, string cur, int i) {
        int n = bottom.size();
        if(bottom.size() == 1)                  // 到达顶层
            return true;
        if(cur.size() == n - 1)                 // 本层构建完毕，递归构建上一层
            return dfs(cur, "", 0);
        if(i == n - 1)                          // 构建失败
            return false;
        string key = { bottom[i], bottom[i+1] };
        if(dict.count(key) == 0)                 // 无法根据任何一条规则构建
            return false;
        else {
            for(char x: dict[key]) {
                if(dfs(bottom, cur + x, i + 1))
                    return true;
            }
        }
        return false;
    }
};
```