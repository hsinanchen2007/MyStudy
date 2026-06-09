蓄水池抽样，概念上理解起来很难，代码上实现不难

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type Solution struct {
	lst *ListNode    
}


/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
func Constructor(head *ListNode) Solution {
	return Solution{lst:head}
}


/** Returns a random node's value. */
func (this *Solution) GetRandom() int {
	res:=this.lst.Val
	head:=this.lst
	head=head.Next
	temp:=2
	for head!=nil{
		i:=rand.Intn(temp)
		if i==0 {
			res=head.Val
		}
		head=head.Next
		temp++
	}
	return res
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(head);
 * param_1 := obj.GetRandom();
 */
```