## 本题按照官方解法有三种方式，dfs,dfs+栈，bfs

### DFS实现
```
//dfs实现
func maxAreaOfIsland(grid [][]int) int {
    if grid==nil || len(grid)==0{
        return 0
    }
    //保存最大值
    max:=0
    //遍历整个岛屿
    for i:=0;i<len(grid);i++{
        for j:=0;j<len(grid[0]);j++{
            //如果grid[i][j]==1,则向上下左右进行搜索，返回上下左右1的个数，即岛屿面积
            if grid[i][j]==1{
                //当前位置的岛屿面积
                tmp:=dfs(grid,i,j)
                //更新最大值
                max=int(math.Max(float64(max),float64(tmp)))
            }
        }
    }
    return max
}
func dfs(grid [][]int,i,j int)int{
    //出递归条件
    if i<0 || i>=len(grid) || j<0 || j>=len(grid[0]) || grid[i][j]==0{
        return 0
    }
    //如果grid[i][j]为1，则将其变为0，向上下左右进行搜索
    //相当于flood fill 染色
    grid[i][j]=0
    return dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1)+1
}
```

### DFS+栈（不使用系统栈，自己定义栈实现）

```
//dfs实现+用栈
func maxAreaOfIsland(grid [][]int) int {
    if grid==nil || len(grid)==0{
        return 0
    }
    //保存最大值
    max:=0
    //定义栈
    stack:=construct()
    //设置横纵坐标的映射（选取len(grid)+len(grid[0])，是为了使映射得到的每个值都不同）
    //如果单独写成len(grid),在有些案例里，存在重复的值，无法实现准确映射
    n:=len(grid)+len(grid[0])
    dx:=[]int{-1,0,1,0}//x的方向
    dy:=[]int{0,-1,0,1}//y的方向
    //遍历整个岛屿
    for i:=0;i<len(grid);i++{
        for j:=0;j<len(grid[0]);j++{
            //当前的岛屿面积
            cur:=0
            //入栈
            stack.push(i*n+j)
            for !stack.empty(){
                index:=stack.pop()
                //获得确切坐标
                curx,cury:=index / n,index % n
                //如果条件不满足则跳过
                if curx<0 || cury<0 || curx>=len(grid) || cury>=len(grid[0]) || grid[curx][cury]==0{
                     continue
                }
                //grid[curx][cury]==1
                cur++
                grid[curx][cury]=0
                //将其他方向的进行入栈
                for k:=0;k<4;k++{
                    index:=(curx+dx[k])*n+(cury+dy[k])
                    stack.push(index)
                } 
            }
            max=int(math.Max(float64(max),float64(cur)))
        }
    }
    return max
}

//实现栈(链表实现)
type Node struct{
    Val int
    Next *Node
}

type stack struct{
    dummy *Node
}

func construct()*stack{
    return &stack{&Node{-1,nil}}
}

func (s *stack)push(x int){
    node:=&Node{x,nil}
    node.Next=s.dummy.Next
    s.dummy.Next=node
}

func (s *stack)pop()int{
    v:=s.dummy.Next.Val
    s.dummy.Next=s.dummy.Next.Next
    return v
}

func (s *stack)peek()int{
    return s.dummy.Next.Val
}

func (s *stack)empty()bool{
    return s.dummy.Next==nil
}
```

### BFS（BFS和DFS+栈实现很像，区别无非就是栈是FILO，相当于不停的向后走，走完再回去。而队列是FIFO，扫描完一圈才开始扫描下一圈。）
```
//bfs实现
func maxAreaOfIsland(grid [][]int) int {
    if grid==nil || len(grid)==0{
        return 0
    }
    max:=0//保存最大值
    //设置横纵坐标的映射（选取len(grid)+len(grid[0])，是为了使映射得到的每个值都不同）
    //如果单独写成len(grid),在有些案例里，存在重复的值，无法实现准确映射
    n:=len(grid)+len(grid[0])
    dx:=[]int{-1,0,1,0}//x的方向
    dy:=[]int{0,-1,0,1}//y的方向
    for i:=0;i<len(grid);i++{
        for j:=0;j<len(grid[0]);j++{
            //当前的岛屿面积
            cur:=0
            queue:=make([]int,0)
            //入队列
            queue=append(queue,i*n+j)
            for len(queue)!=0{
                index:=queue[0]
                curx:=index / n
                cury:=index % n
                queue=queue[1:]
                if curx<0 || cury<0 || curx>=len(grid) || cury>=len(grid[0]) || grid[curx][cury]==0{
                    continue
                }
                cur++
                grid[curx][cury]=0
                for k:=0;k<4;k++{
                    newx:=curx+dx[k]
                    newy:=cury+dy[k]
                    queue=append(queue,newx*n+newy)
                }
            }
            max=int(math.Max(float64(max),float64(cur)))
        }
    }
    return max
}
```

### 本题涉及栈，dfs，bfs，队列知识点，是个好题，之前做的时候只做了dfs就不管了，看来还是理解不深入,做题不仅要做对，还要知其所以然，不然做多了，和没做其实一样，都会忘