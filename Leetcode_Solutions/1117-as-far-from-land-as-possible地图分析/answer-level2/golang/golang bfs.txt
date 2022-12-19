因为是找最长距离，所以需要进行标记式层级遍历（防止在向四个方向探测时重复遍历），遍历层数即是最长距离

![屏幕快照 2019-08-22 10.14.16.png](https://pic.leetcode-cn.com/685b41fc0ff9a20032489842e3db852e15539ca996f688f72a49864588e62f1c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-08-22%2010.14.16.png)


```
type Pair struct {//定义坐标
    X int
    Y int
}
var mX,mY int


func maxDistance(grid [][]int) int {
    mX,mY= len(grid),len(grid[0])
    return bfs(grid)
}


func bfs(grid [][]int)int{
    tmp := make([][]int,mX)//初始化标记矩阵
    for x := range tmp {
        tmp[x]= make([]int,mY)
    }
    
    queueA := make([]*Pair,0)
    for x := range grid {
        for y := range grid {
            if grid[x][y] == 1 {//从陆地节点开始层级遍历
                queueA = append(queueA,&Pair{X:x,Y:y})
                tmp[x][y]=1
            }
        }
    }
    if len(queueA) == 0 ||len(queueA)==mX*mY{//特殊情况检测
        return -1
    }
    tag := &Pair{X:-1,Y:-1}
    queueA = append(queueA,tag)
    
    max := -1
    for ; len(queueA)!=0 ;queueA=queueA[1:]{
        if queueA[0]==tag {//检测一层遍历完成
            max ++
            if len(queueA)!=1 {
                queueA = append(queueA,tag)
            }
            continue
        }
        if tmp[queueA[0].X][queueA[0].Y]==1{//检测
            if 0<=queueA[0].X-1 && tmp[queueA[0].X-1][queueA[0].Y]==0 && grid[queueA[0].X-1][queueA[0].Y]==0{//go left                           
                queueA = append(queueA,&Pair{X:queueA[0].X-1,Y:queueA[0].Y})
                tmp[queueA[0].X-1][queueA[0].Y]=1
            }
            if queueA[0].X+1<mX && tmp[queueA[0].X+1][queueA[0].Y]==0 && grid[queueA[0].X+1][queueA[0].Y]==0{//go right
                queueA =append(queueA,&Pair{X:queueA[0].X+1,Y:queueA[0].Y})
                tmp[queueA[0].X+1][queueA[0].Y]=1
            }
            if 0<=queueA[0].Y-1 && tmp[queueA[0].X][queueA[0].Y-1]==0 && grid[queueA[0].X][queueA[0].Y-1]==0{//go down
                queueA =append(queueA,&Pair{X:queueA[0].X,Y:queueA[0].Y-1})
                tmp[queueA[0].X][queueA[0].Y-1]=1
            }
            if queueA[0].Y+1<mY && tmp[queueA[0].X][queueA[0].Y+1]==0 && grid[queueA[0].X][queueA[0].Y+1]==0{//go up
                queueA =append(queueA,&Pair{X:queueA[0].X,Y:queueA[0].Y+1})
                tmp[queueA[0].X][queueA[0].Y+1]=1
            }
        }
    }
    return max
}
```
