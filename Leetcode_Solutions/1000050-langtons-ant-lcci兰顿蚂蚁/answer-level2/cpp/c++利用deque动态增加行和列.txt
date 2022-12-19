### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> printKMoves(int K) {
        // 数组，如何进行模拟
        if (!K) return {"R"};
        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // 左上右下
        string directions = "LURD";
        deque<deque<char>> map;
        map.push_back(deque<char>(1, '_')); // 出啊石化

        int i = 0, j = 0, d = 2; // 0-4: 左上右下
        int col = 1;
        while (K --) {
            if (map[i][j] == '_') { // 翻转，改变方向
                map[i][j] = 'X';
                d = (d + 1) % 4;
            } else if (map[i][j] == 'X') { // 翻转，改变方向
                map[i][j] = '_';
                d = (d + 3) % 4;
            }

            i += dx[d], j += dy[d]; // 前进

            // 更新地图
            // 增加行
            if (i > (int)map.size() - 1) map.push_back(deque<char>(col, '_'));
            else if (i < 0) map.push_front(deque<char>(col, '_')), i ++;

            // 增加列
            if (j > col - 1) { // 后面增加一列
                for (auto& x: map) x.push_back('_');
                col ++;
            }
            else if (j < 0) { // 前面增加一列
                for (auto& x: map) x.push_front('_');
                j ++, col ++;
            }
        }
        map[i][j] = directions[d]; // 置最终到达单位

        // 收集数据
        vector<string> res;
        for (int i = 0; i < map.size(); i ++) {
            string ans = "";
            for (auto c: map[i]) ans += c;
            res.push_back(ans);
        }
        return res;
    }
};
```