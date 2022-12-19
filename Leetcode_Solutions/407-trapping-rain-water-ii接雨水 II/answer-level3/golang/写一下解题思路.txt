贡献一个Go语言版本的，看视频得到的解题思路。

执行用时 : 316 ms, 在Trapping Rain Water II的Go提交中击败了100.00% 的用户

内存消耗 : 6.3 MB, 在Trapping Rain Water II的Go提交中击败了100.00% 的用户

1. 准备阶段：遍历初始数据，建立一个矩阵地图映射，记录 值，位置，该值是否遍历。
2. 准备阶段：在1遍历过程中，将最边缘的一圈加入列表roundList。
3. 准备阶段：将roundList按照值升序排序，再把排序后的数据加入队列（该队列保证值小的总是在前面）。
4. 遍历阶段：逐个从队列开头取出最小的值，遍历该点的上下左右，如果有未入队的，则入队。
5. 遍历阶段：4入队的时候需要注意，插入合适的地方，保证队列有序。（这是因为要当前遍历值表示了余下的点所能逃逸的最小值）
6. 遍历阶段：遍历到的值p.v如果小于当前记录的最低逃逸点maxp，则表示该点能储水（maxp-p.v）
7. 遍历到队列为空，输出结果

```go
type RainPoint struct {
	x, y, v   int
	IsInQueue bool
}

type RainPointList []*RainPoint

func maxi(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func (r RainPointList) Len() int {
	return len(r)
}
func (r RainPointList) Less(i, j int) bool {
	return r[i].v < r[j].v
}
func (r RainPointList) Swap(i, j int) {
	r[i], r[j] = r[j], r[i]
}
func trapRainWater(heightMap [][]int) int {
	if len(heightMap) < 3 || len(heightMap[0]) < 3 {
		return 0
	}
	rtn := 0
	roundList := make(RainPointList, 0)
	m := map[int]map[int]*RainPoint{}
	xl := len(heightMap[0])
	yl := len(heightMap)
	for y, lines := range heightMap {
		for x, v := range lines {
			rp := &RainPoint{
				x:         x,
				y:         y,
				v:         v,
				IsInQueue: false,
			}
			if x == 0 || y == 0 || y == len(heightMap)-1 || x == len(lines)-1 {
				rp.IsInQueue = true
				roundList = append(roundList, rp)
			}
			if m[y] == nil {
				m[y] = make(map[int]*RainPoint)
			}
			m[y][x] = rp
		}
	}
	sort.Sort(roundList)
	l := list.New()
	for _, v := range roundList {
		l.PushBack(v)
	}
	rm := [][]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
	maxp := 0
	for element := l.Front(); element != nil; element = element.Next(){
		// 上下左右遍历
		rp := element.Value.(*RainPoint)
		maxp = maxi(rp.v, maxp)
		for _, v := range rm {
			x := rp.x + v[0]
			y := rp.y + v[1]
			if x < 0 || x >= xl || y < 0 || y >= yl {
				continue
			}
			p := m[y][x]
			if p.IsInQueue {
				continue
			}
			if p.v < maxp {
				rtn += maxp - p.v
			}
			el := element.Next()
			for {
				if el == nil {
					l.PushBack(p)
					break
				}
				if p.v <= el.Value.(*RainPoint).v {
					l.InsertBefore(p, el)
					break
				}
				el = el.Next()
			}
			p.IsInQueue = true
		}
	}
	return rtn
}
```
