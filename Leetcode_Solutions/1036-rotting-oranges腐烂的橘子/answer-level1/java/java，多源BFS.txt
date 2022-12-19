写一个很简陋的BFS的框架：

```
while(队列不空){
	node=队列.poll();
	for(node的邻接节点){
		if(邻接节点m未曾入队){
			队列.add(m);
		}
	}
}
```

知道了BFS，这道题就比较简单了。

1. 先遍历一遍，统计初始新鲜橘子的数量并将初始腐烂橘子入队。
2. 然后BFS，同时round记录进行了多少轮次的"传染"。每轮开始都要记录当前轮次开始有多少个坏橘子n。
3. 将本轮开始时的所有坏橘子都出队，并对出队节点的四个邻接节点进行判断和"传染"。
4. 最后检查好橘子还有没有。

只有坏橘子才会入队，所以没有框架里邻接节点m未曾入队的检查，因为入过队的都变成坏橘子了。

```java
public int orangesRotting(int[][] grid) {
    int row = grid.length,col=grid[0].length;
    Queue<int[]> queue=new LinkedList<>();
    //遍历，统计新鲜橘子，坏橘子坐标入队
    int count=0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j]==1)count++;
            else if (grid[i][j]==2)queue.add(new int[]{i,j});
        }
    }
    //round传染的轮次
    int round=0;
    //当队列不空并且还存在好橘子就广搜BFS
    while (count>0&&!queue.isEmpty()){
        round++;
        //n记录当前坏橘子数量，防止出队入队导致不同轮次之间混乱
        int n = queue.size();
        for (int i = 0; i < n; i++) {
            int[] rc = queue.poll();
            int r=rc[0],c=rc[1];
            //每个出队的坏橘子的四个正方向上邻接节点是否是好橘子，如果是就传染腐烂并入队
            if (r-1>=0&&grid[r-1][c]==1){
                grid[r-1][c]=2;
                count--;
                queue.add(new int[]{r-1,c});
            }
            if (r+1<row&&grid[r+1][c]==1){
                grid[r+1][c]=2;
                count--;
                queue.add(new int[]{r+1,c});
            }
            if (c-1>=0&&grid[r][c-1]==1){
                grid[r][c-1]=2;
                count--;
                queue.add(new int[]{r,c-1});
            }
            if (c+1<col&&grid[r][c+1]==1){
                grid[r][c+1]=2;
                count--;
                queue.add(new int[]{r,c+1});
            }
        }
    }
    if (count>0)return -1;
    else return round;
}
```

时间复杂度：O(n)	n数组元素个数，整个过程遍历数组两次。

代码很冗长，但是思路还算清楚。

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 