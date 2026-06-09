type LinkNode struct {
	val  int
	Next *LinkNode
}
//生成头节点
func New() *LinkNode {
	//下面的data可以用来表示链表的长度
	return &LinkNode{0, nil}
}

func (head *LinkNode) Insert(i int, e int) bool {
	p := head
	j := 0
	for nil != p && j!=i {
		p = p.Next
		j++
	}
	s := &LinkNode{val: e}
	s.Next=p.Next
	p.Next=s
	return true
}
//暴力
func createTargetArray(nums []int, index []int) []int {
	root:=&LinkNode{val:0}
	length:=0
	for i := 0; i < len(index); i++ {
		if(index[i]>length){
			root.Insert(length,nums[i])
		}else {
			root.Insert(index[i],nums[i])
		}
		length++
	}
	res:=make([]int,len(index))
	p:=0
	root=root.Next
	for root!=nil{
		res[p]=root.val
		root=root.Next
		p++
	}
	return res
}