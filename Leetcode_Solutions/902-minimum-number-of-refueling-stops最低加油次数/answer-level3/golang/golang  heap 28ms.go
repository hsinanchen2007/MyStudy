这题我们不用去考虑还剩多少油，我们直接考虑，总的油还可以走多远。
比如开始我有10L的油，那么我可以走到10，我在5处加了20，那么我就可以走到30处。

我们走到一个加油站，先不用加油，把他存到堆里。用的时候再拿出来。
当我们无法到达最近的加油站时，我们就需要加油了，为了保证加油次数最少，首先拿出最多的油去加。
具体见解题
```
func minRefuelStops(target int, startFuel int, stations [][]int) int {
	fuel := startFuel
	if fuel >= target {
		return 0
	}
	ret := 0
	total := &IntHeap{} // 把所以没有加的油存到堆中
	heap.Init(total)
	for i := 0; i < len(stations); i++ {
		for fuel < stations[i][0] {  // 如果目前走不到这个加油站，我们需要加油
			if total.Len() == 0 { // 没有油可以加，返回
				return -1
			}
			fuel += heap.Pop(total).(int) // 取出最大的油，使用
			ret++ 
		}
		heap.Push(total, stations[i][1]) // 把当前加油站的油放到总池子中，以供下次不够时使用
	}
	for fuel < target {  //  如果没有加油站，且不能到达重点，我们需要检查一下是否还有油可以加，直到没有油或者可以到达终点
		if total.Len() == 0 {
			return -1
		}
		fuel += heap.Pop(total).(int)
		ret++
	}
	return ret
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
```