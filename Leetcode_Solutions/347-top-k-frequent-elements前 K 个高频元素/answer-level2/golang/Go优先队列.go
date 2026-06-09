### 解题思路


### 代码

```golang
func topKFrequent(nums []int, k int) []int {
	var result []int
	freq := make(map[int]int, 0)
	for i := 0; i < len(nums); i++ {
		freq[nums[i]]++
	}
	nodeList := &NodeList{}
	heap.Init(nodeList)

	for key, v := range freq {
		node := Node{
			num:  key,
			freq: v,
		}
		heap.Push(nodeList,node)
		if nodeList.Len() > k{
			heap.Pop(nodeList)
		}
	}
	for nodeList.Len() > 0 {
		node := nodeList.Pop().(Node)
		result = append(result,node.num)
	}

	return result
}

type NodeList []Node

func (n *NodeList) Len() int {
	return len(*n)
}

func (n *NodeList) Less(i, j int) bool {
	return (*n)[i].freq < (*n)[j].freq
}

func (n *NodeList) Swap(i, j int) {
	(*n)[i], (*n)[j] = (*n)[j], (*n)[i]
}

func (n *NodeList) Push(x interface{}) {
	*n = append(*n, x.(Node))
}

func (n *NodeList) Pop() interface{} {
	l := len(*n)
	x := (*n)[l-1]
	*n = (*n)[:l-1]
	return x
}

type Node struct {
	num  int
	freq int
}

```