
外循环从开始走到结尾，遇到当前与下一个相同，开始内循环直到不同。
默认个数为1（本身），遇同++，内循环停止时判断与1的关系。
同代表只有一个，插入。
不同则继续移动。！！注意point指针也要移动。

```
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil{
        return nil
    }
    pre := &ListNode{
		Val: 0,
		Next: head,
	}
	point := pre
	count := 1
	for head != nil && head.Next!=nil { //一定先判断head，这里踩坑了
		for head.Next != nil && head.Val == head.Next.Val {
			count++
			head = head.Next
		}
		if count == 1 {
			point.Next = head
			point = point.Next
			head = head.Next
		} else {
			point.Next = head.Next
			head = head.Next
			count = 1
		}
	}
	return pre.Next
}
```
