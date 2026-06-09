### 解题思路

因为是最少步数，所以使用BFS，当然DFS也能解。

### 代码

```cpp
class Solution {
public:
    // 这一题需要完全匹配谜板，所以可以考虑把数组修改成字符串来处理，比较方便
    int slidingPuzzle(vector<vector<int>>& board) {
        m_target = "123450";

        // 初始状态转化为字符串格式
        string initState;
        for (int i = 0; i < 6; i++) {
            // 0 1 2时 都在第一行，3 4 5在第二行
            int row = i < 3 ? 0 : 1;

            // 只有3列，只能取值0 1 2，所以当大于等于3时，表示成i - 3
            int col = i < 3 ? i : i - 3;
            initState += ('0' + board[row][col]);
        }

        // 如果初始状态与target相等，直接返回
        if (initState == m_target) return 0;

        // 1. 定义一个queue
        queue<string> Q;

        // 2. 定义一个是否访问过的备忘录
        // 这里为了时间复杂度最优，损失了空间，使用hash表来做，这样每次查找是否访问过就是O(1)
        unordered_set<string> visited;

        // 3. 把初始状态加入到队列中，并且标记它已经访问
        Q.push(initState);
        visited.insert(initState);

        // 4. 开始BFS
        // 定义步数，因为此题需要记录，这个不是BFS的标准框架的一部分，根据不同提醒要求
        int steps = 0;
        while (!Q.empty()) {
            // 开始对Q中的状态要发生变化了，所以计数开始
            steps++;

            int size = Q.size();

            // 查看当前队列中所有状态
            while (size-- != 0) {
                string temp = Q.front();
                Q.pop();

                if (Move(temp, Q, visited)) {
                    return steps;
                }
            }
        }

        return -1;
    }

    /*
     * 如果找到返回true，否则返回false
     */
    bool Move(string& curr, queue<string>& Q, unordered_set<string>& visited)
    {
        int zeroPos = curr.find('0');

        // 把'0'位置的row和col计算出来，还记得二维数组二分查找变换为一维数组的做法吧，惯用法
        // 这里3是谜板的列数
        int zeroPosRow = zeroPos / 3;
        int zeroPosCol = zeroPos % 3;

        for (int i = 0; i < 4; i++) {
            int nextPosRow = zeroPosRow + m_direction[i][0];
            int nextPosCol = zeroPosCol + m_direction[i][1];

            // 非法情况排查
            if (nextPosRow < 0 || nextPosRow > 1 || nextPosCol < 0 || nextPosCol > 2) {
                continue;
            }

            // 还需要把next二维换算到一维
            int nextPos = nextPosRow * 3 + nextPosCol % 3;
            swap(curr[zeroPos], curr[nextPos]);
            if (curr == m_target) {
                return true;
            }
            if (!visited.count(curr)) {
                visited.insert(curr);
                Q.push(curr);
            }
            swap(curr[zeroPos], curr[nextPos]);
        }

        return false;
    }
private:
    string m_target;

    // 一般图遍历的四种走法，上下左右（左右上下也都可以）
    vector<vector<int>> m_direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
};
```