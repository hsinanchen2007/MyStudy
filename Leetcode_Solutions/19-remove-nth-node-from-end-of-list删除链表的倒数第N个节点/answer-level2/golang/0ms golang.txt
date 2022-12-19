### 19.删除链表的倒数第N个节点
题意：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

解题思路：遍历一遍链表，计算长度length，并用map存储每个节点，然后删除倒数第N个节点(从0开始计数，第length-n个节点)，仅扫描一次，空间换时间，时间复杂度O(n)
撸完1A
0ms 2.4M
```
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	record := make(map[int]*ListNode)
	index := 0
	record[index] = head
	next := head.Next
	for next != nil{
		index++
		record[index] = next
		next = next.Next
	}
	length := index + 1
	target := length - n
	if target == 0{
		head = record[target].Next
	}else if target == length - 1{
		record[target - 1].Next = nil
	}else{
		record[target - 1].Next = record[target + 1]
	}
	return head
}
```

看题解有个双指针思路，觉得挺巧妙的，原理为让两个指针间隔为n，当后面的指针指向最后一个元素时，前面的指针指向要删除元素的前一个，但是应该还是算扫描了两次，附上解法
0ms 2.2M
```
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	h := new(ListNode)
	result := h
	first := h
	second := h
	h.Next = head
	for i := 0; i < n ; i++ {
		if first != nil{
			first = first.Next
		}
	}
	for first.Next != nil {
		first = first.Next
		second = second.Next
	}
	second.Next = second.Next.Next
	return result.Next
}
``` 