### 解题思路
将多余的加在前几个

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(root *ListNode, k int) []*ListNode {
	n:=0
	head:=root
	cur:=root
	for head!=nil{
		head=head.Next
		n++
	}
	mod:=n%k
	s:=n/k
	res:=make([]*ListNode,k)
	for i:=0;cur!=nil&&i<k;i++{
		var size int
		res[i]=cur
		if mod>0{
			mod--
			size=s+1
		}else{
			size=s
		}
		for j:=0;j<size-1;j++{
			cur=cur.Next
		}
		next:=&ListNode{}
		next = cur.Next;
		cur.Next = nil;
		cur = next;
	}
	return res
}
```