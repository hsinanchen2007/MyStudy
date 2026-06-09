观察表格可以知道，水平或垂直每一行每一列上连续的陆地投影只有2个边，每出现不连续的陆地投影边长就加2，统计完每行每列的结果就是总边长。
```c# []
int sum=0;
        for(var i=0;i<grid.Length;i++){
            int last=-1;
            int count=0;
            for(var j=0;j<grid[0].Length;j++){
                if(grid[i][j]==1){
                    if(last==-1||j==0){
                        last=j;
                        count=2;
                    }else if(grid[i][j-1]==0){
                        last=j;
                        count+=2;
                    }
                }
            }
            sum+=count;
        }
        for(var i=0;i<grid[0].Length;i++){
            int last=-1;
            int count=0;
            for(var j=0;j<grid.Length;j++){
                if(grid[j][i]==1){
                    if(last==-1||j==0){
                        last=j;
                        count=2;
                    }else if(grid[j-1][i]==0){
                        last=j;
                        count+=2;
                    }
                }
            }
            sum+=count;
        }
        return sum;
```

