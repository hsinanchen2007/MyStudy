## 思路
+ 将两个[]int合并成一个[][2]int
+ 先按效率，再按速度逆序排列
+ 遍历新列表，效率是递减的，则当前团队总效率为当前索引位置的效率
+ 用最小堆维护当前团队每一位成员的速度，在团队选择人数超过k时，把速度最慢的一项弹出
+ 新加入的成员不一定能够提升整体效率，因此在每进行一次选择时将新值与旧值相比较

## 代码
```go 
type intHeap []int

func (h intHeap)Len()int{
	return len(h)
}

func (h intHeap)Less(i,j int)bool{
	return h[i]<h[j]
}

func (h intHeap)Swap(i,j int){
	h[i],h[j]=h[j],h[i]
}

func (h *intHeap)Push(x interface{}){
	*h=append(*h,x.(int))
}

func (h *intHeap)Pop()interface{}{
	res:=(*h)[len(*h)-1]
	*h=(*h)[:len(*h)-1]
	return res
}

func max(a,b int64)int64{
	if a>b{
		return a
	}
	return b
}

func maxPerformance(n int, speed []int, efficiency []int, k int) int {
	var (
		res int64
		sum int64
	)
	workerSlice:=make([][2]int,len(efficiency))
	for i:=0;i<len(workerSlice);i++{
		workerSlice[i]=[2]int{speed[i],efficiency[i]}
	}
	sort.Slice(workerSlice, func(i, j int) bool {
		if workerSlice[i][1]==workerSlice[j][1]{
			return workerSlice[i][0]>workerSlice[j][0]
		}
		return workerSlice[i][1]>workerSlice[j][1]
	})
	pq:=&intHeap{}
	heap.Init(pq)
	for i:=0;i< len(workerSlice);i++{
		eff:=int64(workerSlice[i][1])
		sum+=int64(workerSlice[i][0])
		heap.Push(pq,workerSlice[i][0])
		if len(*pq)>k{
			opt:=heap.Pop(pq).(int)
			sum-=int64(opt)
		}
		res=max(res,sum*eff)
	}
	return int(res%1000000007)
}
```