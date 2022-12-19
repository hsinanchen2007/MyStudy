func isValid(s string) bool {
    heap := InitHeap()
    map_pra := map[uint8]uint8{'{':'}', '[':']', '(':')'}
    for i := 0; i < len(s); i++ {
    	if _, ok := map_pra[s[i]]; ok {
    		heap.Push(s[i])
		} else if heap.IsEmpty() || map_pra[heap.Pop().(uint8)] != s[i] {
			return false
		}
	}
	return heap.IsEmpty()
}

type Heap struct {
	Var   interface{}
	Next  *Heap
}

func InitHeap() (heap *Heap){
    heap = new(Heap)
    heap.Next = nil
    return
}

func (self *Heap) Pop() (elem interface{}){
	if self.Next != nil {
		elem = self.Next.Var
		self.Next = self.Next.Next
	}
    return
}

func (self *Heap) Push(elem interface{}) {
    new_elem := new(Heap)
    new_elem.Var = elem
    new_elem.Next = self.Next
    self.Next = new_elem
}

func (self *Heap) Top() (elem interface{}) {
    if self.Next != nil {
    	elem = self.Next.Var
	}
	return
}

func (self *Heap) IsEmpty() bool {
	return self.Next == nil
}

附上github 的地址. https://github.com/liuyanan66/LeetCodeCode/blob/master/LeetCode/lc_20.is_vaild.go