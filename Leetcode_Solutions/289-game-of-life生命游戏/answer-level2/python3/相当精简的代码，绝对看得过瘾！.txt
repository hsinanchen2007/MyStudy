> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/ded1e4f1553387a3b97b4bed837b93c49234a6d9f892e5036538d374ee2a1f76-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


## 题解
这题要求你根据数组每个元素四周的状态来更新数组元素。如果使用一个辅助数组，遍历原数组，然后保存更新后的状态到辅助数组里。这样的话轻轻松松，没有任何难度。但是这题意思是让你不使用辅助数组，直接修改原数组元素，达到一样的目的。

这样的话就不能直接修改原数组元素了，不然当你遍历下一个元素的时候，它周围的值都变掉了，还怎么看它要不要变呢？所以我们应该想办法把变化前变化后的元素都保存下来。

因为这题只有两个状态 0 和 1 ，所以我们可以用两位二进制来表示变化前和后的状态，第一位表示变化后，第二位表示变化前。 00，10，01，11 分别表示 0 不变、0 变到 1 、1 变到 0 、1 不变四种变化情况。这样的话就算你直接修改了元素值，也能获取到它的原来的值。最后只需要进行第二遍扫描，取出变化后的值，也就是第一位就行了。

判断和修改都可以通过位运算来完成。判断修改前是否为 1 可以通过 $x\&1$ 来看。用 m 表示修改（1）或者不修改（0），那么更新后元素就变成了 $x + (m << 1)$ 。最后更新后的数组元素就是 $x >> 1$ 了。

而边界问题很好处理，只需要判断一下有没有超出边界就行了。

## 代码
### c++
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int n = board.size(), m = board[0].size();
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                int cnt = 0;
                for (int i = 0; i < 8; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && (board[nx][ny]&1)) {
                        cnt++;
                    }
                }
                if (board[x][y] == 1) {
                    board[x][y] += ((cnt == 2 || cnt == 3) << 1);
                } else {
                    board[x][y] += ((cnt == 3) << 1);
                }
            }
        }
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                board[x][y] >>= 1;
            }
        }
    }
};
```

### python
```python
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        dx = [-1, -1, -1, 0, 1, 1, 1, 0]
        dy = [-1, 0, 1, 1, 1, 0, -1, -1]
        n, m = len(board), len(board[0])
        for x in range(n):
            for y in range(m):
                cnt = 0
                for i in range(8):
                    nx, ny = x + dx[i], y + dy[i]
                    if 0 <= nx < n and 0 <= ny < m and (board[nx][ny]&1) != 0:
                        cnt += 1
                if board[x][y] == 1:
                    board[x][y] += ((1 if cnt==2 or cnt==3 else 0) << 1)
                else:
                    board[x][y] += ((1 if cnt==3 else 0) << 1)
        for x in range(n):
            for y in range(m):
                board[x][y] >>= 1
```