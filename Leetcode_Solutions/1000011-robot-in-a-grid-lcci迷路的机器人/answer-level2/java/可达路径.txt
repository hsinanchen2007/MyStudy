### 解题思路
要求找一条可达路径即可，但是**答案可能不止一种**

1.会有一条可达路径先被找到，但 **DFS** 会尝试所有的可能(**直到不可达**为止)，在找到了答案的情况下，需要访问标记`boolean[][] visited`**标记已访问，让不可达条件提前出现**，阻止过多不必要的尝试

### 代码

```java
class Solution {
    
    List<List<Integer>> res;
    int row;
    int col;
    boolean[][] visited;
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        row=obstacleGrid.length;
        col=obstacleGrid[0].length;
        visited=new boolean[row][col];
        res=new LinkedList<List<Integer>>();
        if(obstacleGrid[row-1][col-1]==1||obstacleGrid[0][0]==1){
            return res;//起点,终点阻塞,不可达
        }
        DFS(obstacleGrid,0,0,res);
        return res;
    }

    private boolean DFS(int[][] obstacleGrid,int i,int j,List<List<Integer>> path){
        if(i==row-1&&j==col-1){
            List<Integer> temp=new LinkedList<Integer>();
            temp.add(i);
            temp.add(j);
            path.add(temp);
            //DFS不需要像回溯一样重置访问状态
            visited[i][j]=true;    
            return true;
        }
        if(i>=row||j>=col||obstacleGrid[i][j]==1||visited[i][j]){//向下越界、向右越界,阻塞、已访问
            return false;
        }
        
        List<Integer> temp=new LinkedList<Integer>();
        temp.add(i);
        temp.add(j);
        path.add(temp);
        visited[i][j]=true;
        if(DFS(obstacleGrid,i+1,j,path)||DFS(obstacleGrid,i,j+1,path)){
            //只要有一条路径走的通
            return true;
        }    
        //走不通,只能回溯退栈了,走的通就不用退
        path.remove(path.size()-1);
        return false;
    }
}
```