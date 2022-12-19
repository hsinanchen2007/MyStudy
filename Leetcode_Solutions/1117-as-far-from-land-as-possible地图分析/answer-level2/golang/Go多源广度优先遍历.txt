**思路：** 采用多源广度优先遍历，将所有陆地加入到队列中，一层层遍历，最终经过多少层才遍历完成，层数就是距离最远。为什么呢？想象一下同时往平静水面的不同地方丢下石头，不同石头激起的水波速度相同，那么晚水波相遇的点就是距离石头最远的点了。

```go
type Point struct {
    X int
    Y int
}

func maxDistance(grid [][]int) int {
    var queue []*Point
    for i:=0; i < len(grid); i++ {
        for j:=0; j < len(grid[0]); j++ {
            if grid[i][j] == 1 {
                queue = append(queue, &Point{i, j})
            }
        }
    }
    if len(queue) == 0 || len(queue) == len(grid)*len(grid[0]) {
        return -1
    }

    ans := 0
    d := [4][2]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
    for len(queue) > 0 {
        ans++
        tmpQueu := queue
        queue = nil
        for len(tmpQueu) > 0 {
            p := tmpQueu[0]
            tmpQueu = tmpQueu[1:]
            // 以p为原点，检查4个方向
            for i:=0; i < 4; i++ {
                x := p.X + d[i][0]
                y := p.Y + d[i][1]
                if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[0]) || grid[x][y] != 0 {
                    continue
                }
                queue = append(queue, &Point{x, y})
                grid[x][y] = 2 // 代表以及被遍历过了
            }
        }
    }

    return ans-1
}
```
