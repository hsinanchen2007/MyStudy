先算出每辆车辆到达目的地所需的时间,然后按照距目的地的距离排序.  
遍历struct[],取出第一个值,表示当前车队到达需要的时间,判断后车到达时间是否比前车小:  
    是,则表示其会追上前车,二者视为一个车队.  
    否,则刷新最慢到达时间,此后车视为新车队的队头.  
遍历完成,返回最慢到达时间的变化数,则是车队数量.  

```go
type node struct {
	pos   int
	times float64
}

func carFleet(target int, position []int, speed []int) int {
	node := make([]node, len(position))
	if len(position) == 0 {
		return  0
	}
	for i, _ := range position {
		node[i].pos = position[i]
		node[i].times = float64(target-position[i]) / float64(speed[i])
	}
	sort.Slice(node, func(i, j int) bool {
		return node[i].pos > node[j].pos
	})
	sign := node[0].times
	count := 1
	for _, time := range node {
		if time.times > sign {
			count++
			sign = time.times
		}
	}
	return count
}
```