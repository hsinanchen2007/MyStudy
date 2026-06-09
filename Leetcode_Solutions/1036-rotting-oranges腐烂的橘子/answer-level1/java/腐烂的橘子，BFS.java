### 解题思路
按分钟模拟橘子的腐烂，直到没有新的腐烂橘子。

如果结束模拟后如果还有新鲜的橘子，那么就表示有永远不会腐烂的橘子，返回`-1`。

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        int minute = 0;   // 当前模拟的分钟
        int freshOrange = 0; // 检查是否能使得所有橘子腐烂
        int n = grid.length;
        int m = grid[0].length;

        //移动格子参数
        int[] di = new int[] {-1, 1, 0, 0};
        int[] dj = new int[] {0, 0, -1, 1};
        //需要检查的腐烂橘子
        Queue<Node> rotOranges = new LinkedList<Node>(); 

        // 初始化，统计出新鲜的橘子个数 & 把需要检查的腐烂橘子加入队列
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++ j) {
                if (grid[i][j] == 1) {
                    ++ freshOrange;
                } else if (grid[i][j] == 2) {
                    rotOranges.add(new Node(i, j));
                }
            }
        }

        while (freshOrange > 0) {
            //当前时间的腐烂橘子个数
            int currentRot = rotOranges.size();
            for (int k = 0; k < currentRot; ++k) {
                Node cur = rotOranges.poll();
                for (int x=0; x < 4; ++x) {
                    int i = cur.i + di[x];
                    int j = cur.j + dj[x];
                    if (i >=0 && i <n && j >=0 && j < m && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        rotOranges.add(new Node(i, j)); //新加入下一分钟需要检查的腐烂橘子
                    }
                }
            }

            freshOrange -= rotOranges.size();
            if (rotOranges.size() == 0) {
                break;
            }
            ++ minute;
        }

        //System.out.println(freshOrange);
        if (freshOrange > 0) return -1;
        return minute;
    }

    private class Node {
        int i;
        int j;
        Node(int i , int j) {
            this.i = i;
            this.j = j;
        }
    }
}
```