```
type RecentCounter struct {
	queue []int
}

func Constructor() RecentCounter {
	return RecentCounter{queue: make([]int, 0)}
}

func (this *RecentCounter) Ping(t int) int {
	n := t - 3000
	for len(this.queue) > 0 && n > this.queue[0] {
		this.queue = this.queue[1:]
	}
	this.queue = append(this.queue, t)
	return len(this.queue)
}
```
