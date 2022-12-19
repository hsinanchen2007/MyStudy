### 解题思路
图的广搜与树的广搜不同的是：
（1）树只有一个根节点（源节点），图可能有多个源节点，需要先全部添加进来再遍历
（2）由于树有方向性，树的层序遍历（广搜）不需要标记，顺着遍历即可，而图不一样，访问过的结点要标记出，防止陷入死循环
以陆地结点为源节点，向外广搜，访问过的结点置为海洋结点，当遍历结束时，广搜的层数减一即为题目所要求的距离

遍历到最后一趟，都是陆地区域时，就还会循环一次，所以这里step应减一
### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int[][] directions = new int[][]{{1,0},{-1,0},{0,-1},{0,1}};    //方向数组：上、下、左、右
        int step = 0;            //走的步数，即距离

        Queue<Integer> queue = new LinkedList<>();
        int N = grid.length;

        for (int i = 0;i<N;i++){
            for (int j = 0;j<N;j++){
                if (grid[i][j]==1){
                    queue.add(getIndex(i, j, N));
                }
            }
        }

        if (queue.size()==0||queue.size()==N*N){
            return -1;
        }

        while (!queue.isEmpty()){
            int len = queue.size();
            for (int i = 0;i<len;i++){
                int temp = queue.poll();
                int curX = temp/N;
                int curY = temp%N;

                for (int[] direction:directions){
                    int newX = curX+direction[0];
                    int newY = curY+direction[1];
                    if (inArea(newX,newY,N)&&grid[newX][newY]==0){
                        grid[newX][newY] = 1;
                        queue.add(getIndex(newX, newY, N));
                    }
                }

            }
            step++;
        }

        return step-1;//遍历到最后一趟，都是陆地区域时，就还会循环一次，所以这里step应减一
    }

    public int getIndex(int x, int y, int cols){
        return x*cols+y;
    }

    public boolean inArea(int x, int y, int N){
        return x>=0&&x<N&&y>=0&&y<N;
    }
}
```

