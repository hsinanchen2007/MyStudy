![image.png](https://pic.leetcode-cn.com/dd9a65928072679f544441eda6986b1fdfc2b4cfb2d122a262ee3c48cfd9aba1-image.png){:width=600}
{:align=center}


**说明**：以下介绍的算法，除了并查集以外，DFS 和 BFS 都属于很基础的算法内容，也非常好理解，写法也相对固定，读者需要多写，发现并记录自己的问题，我也是在写了几遍甚至是在写本题解的过程中，才发现出自己的问题。


这道题是可以使用一个经典的算法来解决的，那就是 Flood fill，以下的定义来自 [维基百科：Flood fill 词条](https://zh.wikipedia.org/wiki/Flood_fill)。

> **Flood fill 算法**是从一个区域中提取若干个连通的点与其他相邻区域区分开（或分别染成不同颜色）的经典 [算法](https://zh.wikipedia.org/wiki/算法)。因为其思路类似洪水从一个区域扩散到所有能到达的区域而得名。在 [GNU Go](https://zh.wikipedia.org/wiki/GNU_Go) 和 [扫雷](https://zh.wikipedia.org/wiki/扫雷) 中，Flood Fill算法被用来计算需要被清除的区域。

“Flood” 我查了一下，作为动词是 “淹没；充满” 的意思，作为名词是 “洪水” 的意思。下面我们简单解释一下这个算法：

+ 从一个区域中提取若干个连通的点与其他相邻区域区分开

从一个点扩散开，找到与其连通的点，这不是什么高深的算法，其实就是从一个点开始，进行一次 “深度优先遍历” 或者 “广度优先遍历”，通过 “深度优先遍历” 或者 “广度优先遍历” 发现一片连着的区域，对于这道题来说，就是从一个是 “陆地” 的格子开始进行一次 “深度优先遍历” 或者 “广度优先遍历”，把与之相连的所有的格子都标记上，视为发现了一个 “岛屿”。

说明：这里做 “标记” 的意思是，通过 “深度优先遍历” 或者 “广度优先遍历” 操作，我发现了一个新的格子，与起始点的那个格子是连通的，我们视为 “标记” 过，也可以说 “被访问过”。

那么每一次进行 “深度优先遍历” 或者 “广度优先遍历” 的条件就是：

1、这个格子是陆地 `1`，如果是水域 `0` 就无从谈论 “岛屿”；

2、这个格子不能是之前发现 “岛屿” 的过程中执行了 “深度优先遍历” 或者 “广度优先遍历” 操作，而被标记的格子（这句话说得太拗口了，大家意会即可，意会不了不是您的问题，是我表达的问题，直接看代码会清楚很多）。



### 方法一：深度优先遍历

（温馨提示：下面的幻灯片中，有几页上有较多的文字，可能需要您停留一下，可以点击右下角的后退 “|◀” 或者前进 “▶|” 按钮控制幻灯片的播放。）

<![200-dfs-1.png](https://pic.leetcode-cn.com/7e3a5726330949604314953a5cd5a08a8aec627d3c26e74051e848847d7d641f-200-dfs-1.png),![200-dfs-2.png](https://pic.leetcode-cn.com/584d27354c1211a663191e801137dc2663501f0dd9fdc93aed63a80bc24b1294-200-dfs-2.png),![200-dfs-3.png](https://pic.leetcode-cn.com/bf4680d869f0788494937567099837d8af124f8261e37cab6f01474ca236a231-200-dfs-3.png),![200-dfs-4.png](https://pic.leetcode-cn.com/ef66a96fade7df4493fcf8024e9512323cc6ba872c0e787b6b8a96b3be2c2ea9-200-dfs-4.png),![200-dfs-5.png](https://pic.leetcode-cn.com/8bfabda09648fcab6e0bcc724b9eceb8f808c37f505978c191f43dbce0a9e9f9-200-dfs-5.png),![200-dfs-6.png](https://pic.leetcode-cn.com/03600013ece1278ab6459615f58ff6c305cd6781297f8b301b3ae5e5ca8f4de0-200-dfs-6.png),![200-dfs-7.png](https://pic.leetcode-cn.com/4a64b5df2da85cfd2eb297a327a4bc74dc07298443b4a29b0212d0f6a35722b5-200-dfs-7.png),![200-dfs-8.png](https://pic.leetcode-cn.com/1df38a2761c59ab9bd23aa866178541565e3d3bcadfc00d6cef2c4566c5ec2b1-200-dfs-8.png),![200-dfs-9.png](https://pic.leetcode-cn.com/aa1cde39532d32575b6224463789590de06e0df009db67e6631126ae56939963-200-dfs-9.png),![200-dfs-10.png](https://pic.leetcode-cn.com/751f593b32f02e67d18f945fe1e26500bb30713733fd0783f713a18bb0c7e638-200-dfs-10.png),![200-dfs-11.png](https://pic.leetcode-cn.com/12854a4838780f7c117b66b1ff0687302457a755313ecabc7ce95e8ab1a69b44-200-dfs-11.png),![200-dfs-12.png](https://pic.leetcode-cn.com/667e4d61549d9f1b85485acfdf49dd6dd373df2c0b9477e501d0ddf1abb77007-200-dfs-12.png),![200-dfs-13.png](https://pic.leetcode-cn.com/fc4e4d07f48cacbb3185bdbb405bd5223f2f5a549ca0c9f278b7acb9819b1e0e-200-dfs-13.png),![200-dfs-14.png](https://pic.leetcode-cn.com/3e5eda2f0a17a63e196b8fffc506cca2144ac63f12309e2664970773fa0f578a-200-dfs-14.png),![200-dfs-15.png](https://pic.leetcode-cn.com/62f4fbffde817cad7a15f8752f262e23a234b3e45bdbcbf2cac5eba9f6041d3d-200-dfs-15.png),![200-dfs-16.png](https://pic.leetcode-cn.com/2250afc3720069572d38572b56e7ad56e938b5c46dfa44a828e6de80ba21589d-200-dfs-16.png),![200-dfs-17.png](https://pic.leetcode-cn.com/36140b49a185867ef56cdf15c89c108a9d1789a625e1a8d41f99ee109ff6d8b6-200-dfs-17.png),![200-dfs-18.png](https://pic.leetcode-cn.com/ac26b947b46710e23b2862c0dcceb5bfc38a349807c577d4863982f22caabadd-200-dfs-18.png)>


**参考代码：**


```Python []
from typing import List


class Solution:
    #        x-1,y
    # x,y-1    x,y      x,y+1
    #        x+1,y
    # 方向数组，它表示了相对于当前位置的 4 个方向的横、纵坐标的偏移量，这是一个常见的技巧
    directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        # 特判
        if m == 0:
            return 0
        n = len(grid[0])
        marked = [[False for _ in range(n)] for _ in range(m)]
        count = 0
        # 从第 1 行、第 1 格开始，对每一格尝试进行一次 DFS 操作
        for i in range(m):
            for j in range(n):
                # 只要是陆地，且没有被访问过的，就可以使用 DFS 发现与之相连的陆地，并进行标记
                if not marked[i][j] and grid[i][j] == '1':
                    # count 可以理解为连通分量，你可以在深度优先遍历完成以后，再计数，
                    # 即这行代码放在【位置 1】也是可以的
                    count += 1
                    self.__dfs(grid, i, j, m, n, marked)
                    # 【位置 1】
        return count

    def __dfs(self, grid, i, j, m, n, marked):
        marked[i][j] = True
        for direction in self.directions:
            new_i = i + direction[0]
            new_j = j + direction[1]
            if 0 <= new_i < m and 0 <= new_j < n and not marked[new_i][new_j] and grid[new_i][new_j] == '1':
                self.__dfs(grid, new_i, new_j, m, n, marked)


if __name__ == '__main__':
    grid = [['1', '1', '1', '1', '0'],
            ['1', '1', '0', '1', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '0', '0', '0']]
    solution = Solution()
    result = solution.numIslands(grid)
    print(result)
```
```Java []
/**
 * 方法一：深度优先遍历
 */
public class Solution {

    //           x-1,y
    //  x,y-1    x,y      x,y+1
    //           x+1,y
    // 方向数组，它表示了相对于当前位置的 4 个方向的横、纵坐标的偏移量，这是一个常见的技巧
    private static final int[][] directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    // 标记数组，标记了 grid 的坐标对应的格子是否被访问过
    private boolean[][] marked;
    // grid 的行数
    private int rows;
    // grid 的列数
    private int cols;
    private char[][] grid;

    public int numIslands(char[][] grid) {
        rows = grid.length;
        if (rows == 0) {
            return 0;
        }
        cols = grid[0].length;
        this.grid = grid;
        marked = new boolean[rows][cols];
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 如果是岛屿中的一个点，并且没有被访问过
                // 就进行深度优先遍历
                if (!marked[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j);
                }
            }
        }
        return count;
    }

    // 从坐标为 (i,j) 的点开始进行深度优先遍历
    private void dfs(int i, int j) {
        marked[i][j] = true;
        // 得到 4 个方向的坐标
        for (int k = 0; k < 4; k++) {
            int newX = i + directions[k][0];
            int newY = j + directions[k][1];
            // 如果不越界、没有被访问过、并且还要是陆地
            if (inArea(newX, newY) && grid[newX][newY] == '1' && !marked[newX][newY]) {
                dfs(newX, newY);
            }
        }
    }

    // 封装成 inArea 方法语义更清晰
    private boolean inArea(int x, int y) {
        // 等于号不要忘了
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        char[][] grid1 = {
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}};
        int numIslands1 = solution.numIslands(grid1);
        System.out.println(numIslands1);

        char[][] grid2 = {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}};
        int numIslands2 = solution.numIslands(grid2);
        System.out.println(numIslands2);
    }
}
```


### 方法二：广度优先遍历

除了 “深度优先遍历”，你还可以使用 “广度优先遍历”，此时你就不用回溯了。“广度优先遍历” 需要一个 “辅助队列”。

（温馨提示：下面的幻灯片中，有几页上有较多的文字，可能需要您停留一下，可以点击右下角的后退 “|◀” 或者前进 “▶|” 按钮控制幻灯片的播放。）

<![200-bfs-1.png](https://pic.leetcode-cn.com/78a82190bb7ef36df907539975122ae72769bf5cb7eda800fc9977981887f436-200-bfs-1.png),![200-bfs-2.png](https://pic.leetcode-cn.com/4be6649f77d9e25ddd48d87697e4d48f43ab080768795dec6ef1b91d79cc53d7-200-bfs-2.png),![200-bfs-3.png](https://pic.leetcode-cn.com/b34d1c49bea642363609e6d82d5fc43c7cc06de39e45d9f7273929e183d5d4ce-200-bfs-3.png),![200-bfs-4.png](https://pic.leetcode-cn.com/c984aa4df20f7ea16cccb6e084f8fdd3e267d8a218d79dcba29a12a27c8496b7-200-bfs-4.png),![200-bfs-5.png](https://pic.leetcode-cn.com/fcd8f151cdce0c6b32383f23dee71ebd31436d8db75d487206cde24a660831a4-200-bfs-5.png),![200-bfs-6.png](https://pic.leetcode-cn.com/1b64f01a680b01c57d86fba7a9b9151c809f700e91701e61a3273239e49e8453-200-bfs-6.png),![200-bfs-7.png](https://pic.leetcode-cn.com/72641ad9fab5497384012bd3fdc1db760c952d6cccaad9fa8ad8af479c9305c8-200-bfs-7.png),![200-bfs-8.png](https://pic.leetcode-cn.com/e0e147fa90aa180dd33e8743ad9ba3977d08e4fad70d342e46d68f380a5eaf50-200-bfs-8.png),![200-bfs-9.png](https://pic.leetcode-cn.com/8cb1afbd096035b80eccc0451b5fd42370b1d1d4969c4a5b9bcfae3547228376-200-bfs-9.png),![200-bfs-10.png](https://pic.leetcode-cn.com/835e831bfd2651ab7e22a0a27be3e9ec05cce14fedca0cf1e19fcc53ede81017-200-bfs-10.png),![200-bfs-11.png](https://pic.leetcode-cn.com/23783c29d0ef7c777b211eae784fb1725a5d8b17722f5c8cda4dbaaacf398c69-200-bfs-11.png),![200-bfs-12.png](https://pic.leetcode-cn.com/05a57add2f8d3928f2d312f61bce32f3cf0edd939e4e714768e675e301791a46-200-bfs-12.png)>



在写 “广度优先遍历” 的时候，要注意一点：
> 所有加入队列的结点，都应该马上被标记为 “已经访问”，否则有可能会被重复加入队列。

我一开始在编写的时候，等到队列出队的时候才标记 “已经访问”，事实上，这种做法是错误的。因为如果不在刚刚入队列的时候标记 “已经访问”，相同的结点很可能会重复入队，如果你遇到“超时”的提示，你不妨把你的队列打印出来看一下，就很清楚看到我说的这一点。

**参考代码：**

```Python []
from typing import List
from collections import deque


class Solution:
    #        x-1,y
    # x,y-1    x,y      x,y+1
    #        x+1,y
    # 方向数组，它表示了相对于当前位置的 4 个方向的横、纵坐标的偏移量，这是一个常见的技巧
    directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        # 特判
        if m == 0:
            return 0
        n = len(grid[0])
        marked = [[False for _ in range(n)] for _ in range(m)]
        count = 0
        # 从第 1 行、第 1 格开始，对每一格尝试进行一次 DFS 操作
        for i in range(m):
            for j in range(n):
                # 只要是陆地，且没有被访问过的，就可以使用 BFS 发现与之相连的陆地，并进行标记
                if not marked[i][j] and grid[i][j] == '1':
                    # count 可以理解为连通分量，你可以在广度优先遍历完成以后，再计数，
                    # 即这行代码放在【位置 1】也是可以的
                    count += 1
                    queue = deque()
                    queue.append((i, j))
                    # 注意：这里要标记上已经访问过
                    marked[i][j] = True
                    while queue:
                        cur_x, cur_y = queue.popleft()
                        # 得到 4 个方向的坐标
                        for direction in self.directions:
                            new_i = cur_x + direction[0]
                            new_j = cur_y + direction[1]
                            # 如果不越界、没有被访问过、并且还要是陆地，我就继续放入队列，放入队列的同时，要记得标记已经访问过
                            if 0 <= new_i < m and 0 <= new_j < n and not marked[new_i][new_j] and grid[new_i][new_j] == '1':
                                queue.append((new_i, new_j))
                                #【特别注意】在放入队列以后，要马上标记成已经访问过，语义也是十分清楚的：反正只要进入了队列，你迟早都会遍历到它
                                # 而不是在出队列的时候再标记
                                #【特别注意】如果是出队列的时候再标记，会造成很多重复的结点进入队列，造成重复的操作，这句话如果你没有写对地方，代码会严重超时的
                                marked[new_i][new_j] = True
                    #【位置 1】
        return count


if __name__ == '__main__':
    grid = [['1', '1', '1', '1', '0'],
            ['1', '1', '0', '1', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '0', '0', '0']]
    # grid = [["1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "1", "0", "1", "1"],
    #         ["0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "0"],
    #         ["1", "0", "1", "1", "1", "0", "0", "1", "1", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "0", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "0", "1", "1", "1", "0", "1", "1", "1"],
    #         ["0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "0", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "0", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["0", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1"],
    #         ["1", "0", "1", "1", "1", "1", "1", "0", "1", "1", "1", "0", "1", "1", "1", "1", "0", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1", "0"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "0", "0"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"],
    #         ["1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"]]
    solution = Solution()
    result = solution.numIslands(grid)
    print(result)
```
```Java []
import java.util.LinkedList;

/**
 * 方法二：广度优先遍历
 */
public class Solution2 {


    private int rows;
    private int cols;

    public int numIslands(char[][] grid) {
        //           x-1,y
        //  x,y-1    x,y      x,y+1
        //           x+1,y
        int[][] directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        rows = grid.length;
        if (rows == 0) {
            return 0;
        }
        cols = grid[0].length;
        boolean[][] marked = new boolean[rows][cols];
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 如果是岛屿中的一个点，并且没有被访问过
                // 从坐标为 (i,j) 的点开始进行广度优先遍历
                if (!marked[i][j] && grid[i][j] == '1') {
                    count++;
                    LinkedList<Integer> queue = new LinkedList<>();
                    // 小技巧：把坐标转换为一个数字
                    // 否则，得用一个数组存，在 Python 中，可以使用 tuple 存
                    queue.addLast(i * cols + j);
                    // 注意：这里要标记上已经访问过
                    marked[i][j] = true;
                    while (!queue.isEmpty()) {
                        int cur = queue.removeFirst();
                        int curX = cur / cols;
                        int curY = cur % cols;
                        // 得到 4 个方向的坐标
                        for (int k = 0; k < 4; k++) {
                            int newX = curX + directions[k][0];
                            int newY = curY + directions[k][1];
                            // 如果不越界、没有被访问过、并且还要是陆地，我就继续放入队列，放入队列的同时，要记得标记已经访问过
                            if (inArea(newX, newY) && grid[newX][newY] == '1' && !marked[newX][newY]) {
                                queue.addLast(newX * cols + newY);
                                // 【特别注意】在放入队列以后，要马上标记成已经访问过，语义也是十分清楚的：反正只要进入了队列，你迟早都会遍历到它
                                // 而不是在出队列的时候再标记
                                // 【特别注意】如果是出队列的时候再标记，会造成很多重复的结点进入队列，造成重复的操作，这句话如果你没有写对地方，代码会严重超时的
                                marked[newX][newY] = true;
                            }
                        }
                    }
                }
            }

        }
        return count;
    }

    private boolean inArea(int x, int y) {
        // 等于号这些细节不要忘了
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    public static void main(String[] args) {
        Solution2 solution2 = new Solution2();
        char[][] grid1 = {
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}};
        int numIslands1 = solution2.numIslands(grid1);
        System.out.println(numIslands1);

        char[][] grid2 = {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}};
        int numIslands2 = solution2.numIslands(grid2);
        System.out.println(numIslands2);
    }
}
```


### 方法三：使用并查集

使用并查集解决本问题的思想很简单：

1、如果当前是“陆地”，尝试与周围合并一下；

2、如果当前是“水域”，就把所有的“水域”合并在一起，为此，我设置了一个虚拟的结点，表示“所有的水域都和这个虚拟结点是连接的”。

**注意**：

1、针对上面的第 1 点：如果当前是 “陆地”，尝试与周围合并一下”，此时 “周围” 并不需要像 “深度优先遍历” 和 “广度优先遍历” 一样，方向是四周。事实上，只要 “向右”、“向下” 两个方向就可以了，原因很简单，你可以在脑子里想象一个 “4 个方向” 和 “2 个方向” 的算法执行流程（或者看我下面展示的动画），就知道 “4 个方向” 没有必要；

2、针对上面的第 2 点：由于我设置了“虚拟结点”，最后返回“岛屿个数”的时候，应该是连通分量个数 - 1，不要忘记将 “虚拟结点” 代表的 “水域” 分量去掉，剩下的连通分量个数就是 “岛屿个数”。


（温馨提示：下面的幻灯片中，有几页上有较多的文字，可能需要您停留一下，可以点击右下角的后退 “|◀” 或者前进 “▶|” 按钮控制幻灯片的播放。）

<![200-union-find-1.png](https://pic.leetcode-cn.com/3b3a652ef32d81d73be5050f31849137c4077ebc0e80a9d8a2043e2746952815-200-union-find-1.png),![200-union-find-2.png](https://pic.leetcode-cn.com/5cd4cf9b1fd98d66f813f5050f9cf77fc8a42df3c3e7beb829437c0fa167b9d3-200-union-find-2.png),![200-union-find-3.png](https://pic.leetcode-cn.com/09e877e53f190e5107fc88488e73a82be349cff08a9cc8f48cd9e4572c141613-200-union-find-3.png),![200-union-find-4.png](https://pic.leetcode-cn.com/d976c4ae427b918fdc6966ee131d58557c30310f29f420e85bdc03fc2922ff66-200-union-find-4.png),![200-union-find-5.png](https://pic.leetcode-cn.com/bdee38ce299b4d91e8242532e85e59b97437208a9bb0ded572f755fba55efa5c-200-union-find-5.png),![200-union-find-6.png](https://pic.leetcode-cn.com/bfc781d2097685e9c37745048a5410dee8ae9c3529302f250c525afaf116968d-200-union-find-6.png),![200-union-find-7.png](https://pic.leetcode-cn.com/20471c661d026294c1a5df473f86c106c0a82b852c2afb6f7d4b79a3aa4413d3-200-union-find-7.png),![200-bfs-8.png](https://pic.leetcode-cn.com/b876daf1bfc7aa3a6de76a138acb21034eef7e0f28d103da19a4bcdde317b706-200-bfs-8.png),![200-union-find-9.png](https://pic.leetcode-cn.com/7dcc5d6fe003f9ba1e3ff3086f5e2c3721811f1a8b68060b73c7b95e291906b8-200-union-find-9.png),![200-union-find-10.png](https://pic.leetcode-cn.com/5be012a989367f1ddfbb36a97928563eb43ff3d0bb05a52169860a27194910a7-200-union-find-10.png),![200-union-find-11.png](https://pic.leetcode-cn.com/cd22f1986be020f3befa0e5242eff08c9396435485ff9c6dd608b520f91ce217-200-union-find-11.png),![200-union-find-12.png](https://pic.leetcode-cn.com/e682f4adc8656d43aed8e74eaaa8a0baeadd265b1a9b74125b2b582345d1aa12-200-union-find-12.png),![200-union-find-13.png](https://pic.leetcode-cn.com/868e8c2e325a7ac8a60cd61bbde17d1119489c417b6db9fe0ed0f3cbf2bf4f90-200-union-find-13.png),![200-union-find-14.png](https://pic.leetcode-cn.com/cbdddad8ed4c12886129a72c5078eacf9663150005023b62cfd4ab0d86a56cdf-200-union-find-14.png),![200-union-find-15.png](https://pic.leetcode-cn.com/d2c372c65cb3a11f24d323f379d4e63923dbab34256325ede436c37ae4301352-200-union-find-15.png),![200-union-find-16.png](https://pic.leetcode-cn.com/3acd91463484e23cb0b84e32ece96ae6d1f967fb62cae8425332de88a6953c97-200-union-find-16.png),![200-union-find-17.png](https://pic.leetcode-cn.com/5b7ebb04d391437daac1da0d84e35c5a6ea91b16bf1519148efd0361bc95d322-200-union-find-17.png),![200-union-find-18.png](https://pic.leetcode-cn.com/ccc9dbc10a61218638925ac534e8b4dff0b19e04dc686fd370cc1812b46752ed-200-union-find-18.png),![200-union-find-19.png](https://pic.leetcode-cn.com/8bcb9b73e3ec7655a9d954d48ec5ffe23605e089a356ddee3b03392b0f2ea642-200-union-find-19.png),![200-union-find-20.png](https://pic.leetcode-cn.com/5435d4e23aa9dd3074bbb57b37881394fdddc0d0d8f7fa283a15ab0b40c79cd3-200-union-find-20.png),![200-union-find-21.png](https://pic.leetcode-cn.com/384581ac030c30963d223aab2a7cfccdf22cb5ee6165733e9f2dbe686e7f2c1c-200-union-find-21.png)>




**参考代码：**

```Python []
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        class UnionFind:

            def __init__(self, n):
                self.count = n
                self.parent = [i for i in range(n)]
                self.rank = [1 for _ in range(n)]

            def get_count(self):
                return self.count

            def find(self, p):
                while p != self.parent[p]:
                    self.parent[p] = self.parent[self.parent[p]]
                    p = self.parent[p]
                return p

            def is_connected(self, p, q):
                return self.find(p) == self.find(q)

            def union(self, p, q):
                p_root = self.find(p)
                q_root = self.find(q)
                if p_root == q_root:
                    return

                if self.rank[p_root] > self.rank[q_root]:
                    self.parent[q_root] = p_root
                elif self.rank[p_root] < self.rank[q_root]:
                    self.parent[p_root] = q_root
                else:
                    self.parent[q_root] = p_root
                    self.rank[p_root] += 1

                self.count -= 1

        row = len(grid)
        # 特判
        if row == 0:
            return 0
        col = len(grid[0])

        def get_index(x, y):
            return x * col + y

        # 注意：我们不用像 DFS 和 BFS 一样，4 个方向都要尝试，只要看一看右边和下面就可以了
        directions = [(1, 0), (0, 1)]
        # 多开一个空间，把水域 "0" 都归到这个虚拟的老大上
        dummy_node = row * col

        # 多开的一个空间就是那个虚拟的空间
        uf = UnionFind(dummy_node + 1)
        for i in range(row):
            for j in range(col):
                # 如果是水域，都连到那个虚拟的空间去
                if grid[i][j] == '0':
                    uf.union(get_index(i, j), dummy_node)
                if grid[i][j] == '1':
                    # 向下向右如果都是陆地，即 "1"，就要合并一下
                    for direction in directions:
                        new_x = i + direction[0]
                        new_y = j + direction[1]
                        if new_x < row and new_y < col and grid[new_x][new_y] == '1':
                            uf.union(get_index(i, j), get_index(new_x, new_y))
        # 不要忘记把那个虚拟结点减掉
        return uf.get_count() - 1


if __name__ == '__main__':
    grid = [['1', '1', '1', '1', '0'],
            ['1', '1', '0', '1', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '0', '0', '0']]
    solution = Solution()
    result = solution.numIslands(grid)
    print(result)
```