### 解题思路
本题类似排列组合，使用一个数组或者位图来记录以访问的元素
1. 在每次迭代时，产生一个结果，需要记录
2. 为避免本轮回溯产生重复，需记录前后访问字符是否相同，为此需对tiles进行排序，在回溯循环中比对去重

### 代码

```cpp
class Solution {
public:
    int numTilePossibilities(string tiles) {
        if (tiles.empty()) {
            return 0;
        }
        int res = 0;
        string s;
        vector<bool> visited(tiles.size(), false);
        sort(tiles.begin(), tiles.end());
        dfs(tiles, visited, s, res);
        return res;
    }

    void dfs(string& tiles, vector<bool>& visited, string& s, int& res) {
        if (!s.empty()) {
            ++res;
        }

        char pre = '#'; // 标记，避免本次回溯访问到相同的字符
        for (int i = 0, sz = tiles.size(); i < sz; ++i) {
            if (pre == tiles[i]) {
                continue;
            }

            if (!visited[i]) {
                pre = tiles[i];
                s.push_back(tiles[i]);
                visited[i] = true;
                dfs(tiles, visited, s, res);
                s.pop_back();
                visited[i] = false;
            }
        }
    }
};
```