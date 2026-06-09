### 解题思路
* 借鉴牛人 ijkbytesss 的思路： 采用多源广度优先遍历，将所有陆地加入到队列中，一层层遍历，最终经过多少层才遍历完成，层数就是距离最远。为什么呢？想象一下同时往平静水面的不同地方丢下石头，不同石头激起的水波速度相同，那么晚水波相遇的点就是距离石头最远的点了（这个比喻非常形象）
* 注意提交的代码别附带fmt.Print,容易超时



### 代码

```golang
func maxDistance(grid [][]int) int {
  maxDistance:= -1
  var queue []Point

  gridN := len(grid)
  for i:=0;i<gridN;i++{
    for j:=0;j<gridN;j++{
      if grid[i][j] == 1{
        queue = append(queue, Point{i,j,0})
      }
    }
  }
  if len(queue) ==0 || len(queue) == gridN*gridN{return -1}

  for len(queue)>0{
    //fmt.Println(queue)
    cur := queue[0]

    // 往左
    if cur.x - 1 >= 0{
      if grid[cur.x-1][cur.y] == 0{
        if cur.dist + 1 > maxDistance {maxDistance = cur.dist + 1}
        grid[cur.x-1][cur.y] = 2
        queue = append(queue,Point{cur.x-1,cur.y,cur.dist+1})
      }
    }
    // 向右
    if cur.x + 1 < gridN{
      if grid[cur.x+1][cur.y] == 0{
        if cur.dist + 1 > maxDistance {maxDistance = cur.dist + 1}
        grid[cur.x+1][cur.y] = 2
        queue = append(queue,Point{cur.x+1,cur.y,cur.dist+1})
      }
    }
    // 往上
    if cur.y - 1 >= 0{
      if grid[cur.x][cur.y-1] == 0{
        if cur.dist + 1 > maxDistance {maxDistance = cur.dist + 1}
        grid[cur.x][cur.y-1] = 2
        queue = append(queue,Point{cur.x,cur.y-1,cur.dist+1})
      }
    }
    // 向右
    if cur.y + 1 < gridN{
      if grid[cur.x][cur.y+1]==0{
        if cur.dist + 1 > maxDistance {maxDistance = cur.dist + 1}
        grid[cur.x][cur.y+1] = 2
        queue = append(queue,Point{cur.x,cur.y+1,cur.dist+1})
      }
    }

    queue = queue[1:]
  }
  return maxDistance
}

type Point struct{
  x int
  y int
  dist int
}
```