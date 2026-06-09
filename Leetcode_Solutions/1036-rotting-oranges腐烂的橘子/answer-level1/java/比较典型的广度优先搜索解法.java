### 解题思路

**首先这题标了easy，个人觉得不太合理，因为无论从代码角度还是从题目分析的角度来说都应该至少是medium级别的题目。**

先来看下执行效率:

执行用时: 4 ms, 在所有 Java 提交中击败了45.60%的用户;
内存消耗: 38.5 MB, 在所有 Java 提交中击败了54.90%的用户;

咋一看其实BFS算法的实现效率不是太高，一般来说广度优先搜索不如深度优先搜索的执行效率来的高。

然后再来看下这个广度优先搜索算法的复杂度分析：

时间复杂度:O(n * m); 即进行一次广度优先搜索的时间，其中 n=grid.length , m=grid[0].length;
空间复杂度:O(n * m); 需要额外的 disdis 数组记录每个新鲜橘子被腐烂的最短时间，大小为 O(n * m), 且广度优先搜索中队列里存放的状态最多不会超过 n*m 个，最多需要 O(n * m)的空间，所以最后的空间复杂度为 O(n * m)；

在下面的广度优先算法中有两个点需要重点关注的；
(1)在grid二位数组中橘子不一定只有1个烂掉，所以**一开始加入广度优先搜索队列中的会是多个元素**；

(2)二位数组grid在广度优先搜索队列中的的表示方法，一般也有如下：
a.数学乘法和取模运算,对于(i, j), 可以将其根据运算表示为: **value = i * cols + j;**(其中cols为二位数组grid的列数);
反过来，将value还原成(i, j)也是一样的，**i = value/cols, j = value%cols**；

b.使用类似java中Pair这样子的键值类元素对象来表示也可以的(**new Pair<i, j>**)；

(3)需要借助哈希表HashMap, 来保存最广度优先搜索的深度, 该深度也是最后题目所要求的答案， **因为到达二位数组grid中最后一个烂掉橘子时候是depth最深的时候，也几位单元格中没有新鲜橘子的最小时间；**

(4)最后还需要检查下二位数组grid中是否有新鲜的橘子(**说明图中有节点不可达**)，如果存在则返回-1;

### 代码

```java
class Solution {


    int[][] direction = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public int orangesRotting(int[][] grid) {

        if (grid == null || grid.length == 0) {
            return 0;
        }

        int nr = grid.length;
        int nc = grid[0].length;

        Deque<Integer> queue = new ArrayDeque<Integer>();
        HashMap<Integer, Integer> depth = new HashMap<Integer, Integer>();

        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == 2) {
                    int node = i * nc + j;
                    queue.add(node);
                    depth.put(node, 0);
                }
            }
        }

        int ans = 0;
        while (!queue.isEmpty()) {
            int node = queue.remove();
            int row = node / nc;
            int col = node % nc;
            for(int i = 0; i < 4; i++) {
                int newx = row + direction[i][0];
                int newy = col + direction[i][1];

                if (newx >= 0 && newx < nr
                        && newy >=0 && newy < nc && grid[newx][newy] == 1) {
                    grid[newx][newy] = 2;
                    int newNode = newx * nc + newy;
                    queue.add(newNode);
                    depth.put(newNode, depth.get(node) + 1);
                    ans = depth.get(newNode);
                }
            }
        }

        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                if (grid[r][c] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
}
```