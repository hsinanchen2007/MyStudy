### 解题思路
此处撰写解题思路

### 代码

```golang
func getLength(head *ListNode) int {
	res := 0
	if head == nil {
		return res
	}
	cur := head
	for cur != nil {
		res++
		cur = cur.Next
	}
	return res
}
func reverseOne(head *ListNode, k int,index,count int)  *ListNode {
	if index >count{
		return head
	}
	i := 0
	cur := head
	var pre *ListNode
	for i < k {
		tmp:=cur
		cur=cur.Next
		tmp.Next=pre
		pre=tmp
		i++
	}
	head.Next=reverseOne(cur, k,index+1,count)
	return pre
}
func reverseKGroup(head *ListNode, k int) *ListNode {
	length := getLength(head)
	count := length / k
	resHead:=reverseOne(head, k,1,count)
	return resHead
}

```