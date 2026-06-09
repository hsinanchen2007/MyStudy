### 解题思路
此处撰写解题思路
首先明白岛屿是指的内部都是1，周边是0或者数组边界的一群1。所以从for循环数组开始
1. 如何确定数组起点周边的情况呢？刚开始就想到用dfs去递归上下左右四个方向，然后递归我们都知道要有个跳出条件或者结束条件，这道题目有点特殊，仔细想一下，周边是0的话就不再递归找了，这样子就确定了结束条件；
2. 然后岛屿数最开始数组种每个数都要开始去找，但是如果两个数相近，是否都要遍历呢？不需要，我们dfs的时候，如果这个点找过，就置为0，因为找过的点，他就算在起点的那个岛上了，所以dfs要将找过的点置为0。
这样整体思路就是这样了
### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        int num = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    num++;
                }
            }
        }
        return num;
    }


// 深度优先
    public void dfs(int i,int j,char[][] grid){
        grid[i][j] = 0;
        if(i-1 >=0 && grid[i-1][j] == '1'){
            dfs(i-1,j,grid);
        }
        if(i+1 <=grid.length-1 && grid[i+1][j] == '1'){
            dfs(i+1,j,grid);
        }
        if(j-1 >=0 && grid[i][j-1] == '1'){
            dfs(i,j-1,grid);
        }
        if(j+1 <=grid[i].length-1 && grid[i][j+1] == '1'){
            dfs(i,j+1,grid);
        }
    }
}
```