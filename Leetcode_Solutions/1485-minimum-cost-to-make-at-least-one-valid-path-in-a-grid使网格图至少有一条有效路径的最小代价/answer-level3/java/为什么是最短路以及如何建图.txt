### 解题思路
当你老想着要如何生成一条有效路径的时候，你就陷入了泥沼。

这样说你就明白了，不管每个格子的方向是什么，**最差情况下，你总是可以花 `n-1+m-1`改方向最终到达终点**。随便举个例子比如改成下图这样。

![image.png](https://pic.leetcode-cn.com/4caca8865b989c6e3e695daf7c1614fbcedddc6489b4c4f97c5d776f1fbdce2a-image.png)

**也就是说，路本来就是存在的，不需要你去生成！每个点与周围四个点的距离（花费）原本就是 1，只不过其中一个方向不需要花费，距离是 0.**

然后求`{0,0}`到`{m-1,n-1}`的最短路即可

说到这建图也就没啥问题了，每个点与相邻的三个点距离为 1，另一个点距离为 0。


### 双百代码（SPFA）

```java
class Solution {
    int m;
    int n;
    public int minCost(int[][] grid) {
        m=grid.length;
        n=grid[0].length;
        Deque<Integer> q=new ArrayDeque<>();
        int[] dist=new int[m*n+1];
        Arrays.fill(dist,-1);
        int[][] directions=new int[][]{{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        q.add(0);
        dist[0]=0;
        while(!q.isEmpty()){
            int curr=q.peek();
            int currRow=curr/n;
            int currCol=curr%n;
            for(int i=1;i<=4;i++){
                int nextRow=currRow+directions[i][0];
                int nextCol=currCol+directions[i][1];
                int next=nextRow*n+nextCol;
                if(!valid(nextRow,nextCol)) continue;
                int distFromCurr=dist[curr]+(grid[currRow][currCol]==i?0:1);
                if(dist[next]==-1||dist[next]>distFromCurr){
                    dist[next]=distFromCurr;
                    if(!q.contains(next)){
                        q.add(next);
                    }
                }
            }
            q.pop();
        }
        return dist[m*n-1];
    }
    private boolean valid(int row,int col){
        if(row<0||row>=m||col<0||col>=n) return false;
        return true;
    }
}
```