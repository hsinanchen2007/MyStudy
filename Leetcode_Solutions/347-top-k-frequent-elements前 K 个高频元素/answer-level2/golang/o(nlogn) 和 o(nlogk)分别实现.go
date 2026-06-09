//o(nlogn)
```
func topKFrequent(nums []int, k int) []int {
    numsmap := make(map[int]int)
    type num struct {
        val int
        key int
    }
    var valkey []num
    var result []int
    for _, v := range nums {
        numsmap[v] ++
    }
    for k, v := range numsmap {
        valkey = append(valkey, num{k, v})
    }
    sort.Slice(valkey, func (i, j int) bool {
        return valkey[i].key > valkey[j].key  
    })
    for i, v := range valkey {
        if i == k {
            break
        }
        result = append(result, v.val)
    }   
    return result
}
```



//o(nlogk)
```
type mapheap struct {
	key int
	val int
}
type IntHeap []*mapheap
func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i].val < h[j].val }
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(*mapheap)) }
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func topKFrequent(nums []int, k int) []int {
    numsmap := make(map[int]int)
    var result []int
    for _, v := range nums {        //map统计元素频率
        numsmap[v] ++
    }
    h := &IntHeap{}
    heap.Init(h)
    for key, val := range numsmap {
        if h.Len() < k {
            heap.Push(h, &mapheap{key, val})   
        }else if val > (*h)[0].val {        //每次比较维护好的小顶堆堆顶元素更新即可
            heap.Pop(h)
            heap.Push(h, &mapheap{key, val})
        } 
    }
    for _, v := range *h {
        result = append(result,v.key)
    }   
    return result
}
```
