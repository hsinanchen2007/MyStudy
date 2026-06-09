效率不高，主要练习Go语言的list使用
```
func maxAreaOfIsland(grid [][]int) int {
    var m int = len(grid);
    if m==0 {
        return 0;
    }
    var move [][]int = [][]int{{1,0},{-1,0},{0,1},{0,-1}};
    var n int = len(grid[0]);
    var area int = 0;
    var temp int = 0;
    queue:=list.New();
    for i:=0;i<m;i++ {
        for j:=0;j<n;j++ {
            if grid[i][j]==1 {
                temp=1;
                queue.PushBack([2]int{i,j});
                grid[i][j]=0;
                for queue.Len()>0 {
                    s:=queue.Front();
                    array := s.Value.([2]int);
                    queue.Remove(s);
                    for k:=0;k<4;k++ {
                        a:=array[0]+move[k][0];
                        b:=array[1]+move[k][1];
                        if isArea(a,b,m,n) && grid[a][b]==1 {
                            grid[a][b] = 0;
                            temp++;
                            queue.PushBack([2]int{a,b});
                        }
                    }
                }
                if area<temp {
                    area=temp;
                }
            }
        }
    }
    return area;
}
func isArea(x int,y int,m int,n int) bool{
    return x>=0 && y>=0 && x<m && y<n;
}
```
