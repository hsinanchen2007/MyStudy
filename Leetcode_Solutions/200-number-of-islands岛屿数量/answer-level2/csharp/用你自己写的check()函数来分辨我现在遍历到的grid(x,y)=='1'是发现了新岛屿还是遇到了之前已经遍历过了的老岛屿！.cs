第一步：申明一个和gird一样大的bool型数组，如果我们确定了grid[x][y]是某个已知岛屿的一部分，就在map[x,y]里将他赋值为true，以后遍历的时候我们就会跳过这个坐标，最后声明一个answer=0，answer是岛屿数量，也是我们最后要输出的值
第二步：遍历整个grid，如果遇到1，而且这个区域在map数组中为false，则answer++运行你自己写的check()函数，check()函数的作用是：
1.检查当前遍历到的这个位置，在grid中是否为1
2.如果是1，我们就在map里相同位置给他赋值为true，表示他是一个已知岛屿的一部分，以后遍历到这里时程序就会知道"哦！这不是新发现的新岛屿，这个岛屿我之前就发现过了，不用给岛屿数量+1"
3.去check()自己上下左右4块区域！
第三步：继续遍历，如果遇到在grid数组中为1，在map数组中为false的区域，就说明我们遇到了新的岛屿，answer++并且chech()
最后一步：遍历完输出answer就好啦！


```
public class Solution {

    public void check(int x,int y,char[][] grid,ref bool[,] map){
        if(grid[x][y]=='0'||map[x,y]==true){return;}
        map[x,y]=true;
        if(x<grid.Length-1){check(x+1,y,grid,ref map);}
        if(x>0){check(x-1,y,grid,ref map);}
        if(y<grid[0].Length-1){check(x,y+1,grid,ref map);}
        if(y>0){check(x,y-1,grid,ref map);}
    }

    public int NumIslands(char[][] grid) {

        if(grid==null||grid.Length==0){return 0;}//特殊情况处理

        bool[,] map=new bool[grid.Length,grid[0].Length];
        int answer=0;

        for(int i=0;i<grid.Length;i++){
            for(int j=0;j<grid[0].Length;j++){
                
                if(map[i,j]==true){continue;}//如果这个区域已被处理，则跳过哦owo

                if(grid[i][j]=='1'){
                    answer++;
                    check(i,j,grid,ref map);
                }
                
            }
        }
    return answer;
    }
}
```
