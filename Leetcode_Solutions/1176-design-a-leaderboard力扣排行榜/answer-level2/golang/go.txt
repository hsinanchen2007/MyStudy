### 解题思路
此处撰写解题思路

### 代码

```golang
type Leaderboard struct {
	m    map[int]int
	pq   priorityQueu
	tokM map[int]int
}

func Constructor() Leaderboard {
	l := Leaderboard{m: map[int]int{}, pq: priorityQueu{}, tokM: map[int]int{}}
	heap.Init(&(l.pq))
	return l
}

func (this *Leaderboard) AddScore(playerId int, score int) {
	this.m[playerId] += score
	for k, v := range this.m {
		heap.Push(&(this.pq), &item{
			priority: v,
			playerId: k,
		})
	}
	sum := 0
	index := 1
	for this.pq.Len() > 0 {
		sum += heap.Pop(&(this.pq)).(*item).priority
		this.tokM[index] = sum
		index++
	}
}

func (this *Leaderboard) Top(K int) int {
	return this.tokM[K]
}

func (this *Leaderboard) Reset(playerId int) {
	delete(this.m, playerId)
	for k, v := range this.m {
		heap.Push(&(this.pq), &item{
			priority: v,
			playerId: k,
		})
	}

	sum := 0
	index := 1
	for this.pq.Len() > 0 {
		sum += heap.Pop(&(this.pq)).(*item).priority
		this.tokM[index] = sum
		index++
	}
}

type item struct {
	priority int
	playerId int
}
type priorityQueu []*item

func (p priorityQueu) Len() int {
	return len(p)
}

func (p priorityQueu) Less(i, j int) bool {
	return p[i].priority > p[j].priority
}

func (p priorityQueu) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p *priorityQueu) Push(x interface{}) {
	*p = append(*p, x.(*item))
}

func (p *priorityQueu) Pop() interface{} {
	length := p.Len()
	v := (*p)[length-1]
	*p = (*p)[:length-1]
	return v
}

```