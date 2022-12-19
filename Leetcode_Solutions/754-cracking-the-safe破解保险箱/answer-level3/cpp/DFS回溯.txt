### 解题思路

可以看作 n-1位数字 的 欧拉路径，或者 n位数字的 哈密尔顿路径。

### 代码

```cpp
class Solution {
private:
    unordered_set<string> visited;
public:
    string crackSafe(int n, int k) {
        string res(n, '0');
        visited.insert(res);
        dfs(res, pow(k, n), n, k);
        return res;
    }
    
    bool dfs(string& cur, int total, int n, int k) {
        if(visited.size() == total)
            return true;
        for(int i=0; i<k; i++) {
            string next = cur.substr(cur.size() - n + 1, n - 1) + to_string(i);
            if(visited.count(next) == 0) {
                visited.insert(next);
                cur.push_back('0' + i);
                if(dfs(cur, total, n, k))
                    return true;
                else {
                    visited.erase(next);
                    cur.pop_back();
                }
            }
        }
        return false;
    }
};
```