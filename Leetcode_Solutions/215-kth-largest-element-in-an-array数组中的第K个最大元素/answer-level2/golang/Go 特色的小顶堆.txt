```
func findKthLargest(nums []int, k int) int {
    if len(nums) < 1||k>len(nums) {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    }
    h := &myHeap{}
    heap.Init(h)//初始化堆
    for i:=0;i<len(nums);i++{
        if h.Len() < k{            //插入元素构建只有k个元素的小顶堆
            heap.Push(h,nums[i])
            continue
        }
        if nums[i]>(*h)[0]{    //如果比堆顶元素大
            heap.Pop(h)
            heap.Push(h,nums[i])
        }    
    }
    //最后堆顶元素就是第K大的数
    return (*h)[0]
  
}

//构建堆

type myHeap []int

//实现对应接口

func (h myHeap)Len()int{
    return len(h)
}

func (h myHeap)Less(i,j int)bool{
    return h[i]<h[j]
}

func (h myHeap)Swap(i,j int){
    h[i],h[j] = h[j],h[i]
}

func (h *myHeap)Push(x interface{}){
    *h = append(*h,x.(int))
}

func (h *myHeap)Pop()interface{}{
    old := *h 
    l := len(old)
    x := old[l-1]
    *h = old[:l-1] 
    return x
}


```
