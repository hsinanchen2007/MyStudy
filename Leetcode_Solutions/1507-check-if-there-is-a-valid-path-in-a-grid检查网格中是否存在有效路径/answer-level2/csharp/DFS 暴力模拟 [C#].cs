判断下一个格子是否可以和当前格子接上(valid)，并字典记录已经访问过的格子(visited[i][j])。
只要到了一次终点就可以了。
```
public class Solution {
    int[,] visited;
    public bool HasValidPath(int[][] grid) {
        visited=new int[grid.Length,grid[0].Length];
        return Search(grid,0,0,new List<int>(){1,2,3,4,5,6});
    }
    
    public bool Search(int[][]grid, int i,int j,List<int> valid){
        if(i>=grid.Length||j>=grid[0].Length||i<0||j<0) return false;
        if(visited[i,j]==0){
            visited[i,j]=1;
        }
        else{
            return false;
        }
        if(!valid.Contains(grid[i][j])) return false;
        if(i==grid.Length-1&&j==grid[0].Length-1){
            return true;
        }
        bool result=false;
        if(grid[i][j]==1){
            result|=Search(grid,i,j+1,new List<int>(){1,3,5});
            result|=Search(grid,i,j-1,new List<int>(){1,4,6});
        }
         if(grid[i][j]==2){
            result|=Search(grid,i+1,j,new List<int>(){2,5,6});
            result|=Search(grid,i-1,j,new List<int>(){2,3,4});
        }
        if(grid[i][j]==3){
            result|=Search(grid,i,j-1,new List<int>(){4,6,1});
            result|=Search(grid,i+1,j,new List<int>(){5,6,2});
        }
        if(grid[i][j]==4){
            result|=Search(grid,i,j+1,new List<int>(){1,3,5});
            result|=Search(grid,i+1,j,new List<int>(){5,6,2});
        }
        if(grid[i][j]==5){
            result|=Search(grid,i-1,j,new List<int>(){2,3,4});
            result|=Search(grid,i,j-1,new List<int>(){4,6,1});
        }
        if(grid[i][j]==6){
            result|=Search(grid,i-1,j,new List<int>(){2,3,4});
            result|=Search(grid,i,j+1,new List<int>(){1,3,5});
        }
        return result;
    }
}
```
