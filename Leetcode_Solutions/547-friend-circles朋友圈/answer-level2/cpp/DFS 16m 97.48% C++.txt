### 解题思路
思路总起来就是顺藤摸瓜, 从同学i开始查朋友圈, 查到一个朋友就拉黑一个朋友, 用一个数组记录所有同学有没有被拉黑.
用递归的方式查朋友圈, 具体可以看下代码, 同学i就是矩阵的第y行, 顺藤摸瓜的思路就是这一行里的所有朋友都是瓜.
![1.png](https://pic.leetcode-cn.com/210841377ce022f4d0e544fe864db6811d91c825c67649fd4a2e31b5fb4060d7-1.png)

### 代码

```cpp
class Solution {
public:
    int count = 0;
    vector<vector<int>> _M;
    vector<bool> state;

    int findCircleNum(vector<vector<int>>& M) {
        this->_M = M;
        this->state.resize(M.size(), true);
        // 从第i个同学开始查朋友圈
        for (int i = 0; i < M.size(); i++) {
            if (state[i]) {
                dfs(i);
                ++count;  // 每查一次会拉黑一拨人, 记在state里, 拉黑一波就++count
            }
        }

        return count;
    }
    void dfs(int y) {
        int x = 0;
        for (int x = 0; x < _M.size(); x++) {
            if (state[x] and _M[y][x]) {
                state[x] = false;
                if (x == y) continue;
                dfs(x);  // 递归一路查下去
            }
        }
    }
};
```