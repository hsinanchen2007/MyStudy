### 解题思路
我自己实现的方式是，新开个链表，逐个比较储存。代码写的比较冗杂。
究其原因是for循环的条件是 l1!=nil||l2!=nil，导致在内部要进行大量的校验!=nil操作
其实只要遍历最短的一条就ok了，遍历结束后，直接拼接到结尾便可。


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

//自己的实现方式
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	result:=new(ListNode)
	head:=result
	for l1!=nil||l2!=nil{
		var v1 int=math.MaxInt32
		var v2 int =math.MaxInt32
		var currentNode =new(ListNode)
		var currentValue int
		if l1!=nil{
			v1=l1.Val
		}

		if l2!=nil{
			v2=l2.Val
		}

		if v1<v2{
			currentValue=v1
			l1=l1.Next
		}else{
			currentValue=v2
			l2=l2.Next
		}
		currentNode.Val=currentValue
		head.Next=currentNode
		head=currentNode
	}
	return result.Next
}

//别人好的实现方式
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{} //头结点
	cursor := head      //指针
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cursor.Next = l1
			l1 = l1.Next
		} else {
			cursor.Next = l2
			l2 = l2.Next
		}
		cursor = cursor.Next
	}
	//任一条到达尾部，直接拼上另一条
	if l1 == nil {
		cursor.Next = l2
	} else {
		cursor.Next = l1
	}
	return head.Next
}

```