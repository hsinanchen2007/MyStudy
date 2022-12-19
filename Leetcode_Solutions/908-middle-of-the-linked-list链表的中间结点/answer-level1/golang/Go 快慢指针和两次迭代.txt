## 快慢指针

使用快慢指针，快指针到尾部到时候慢指针正好在中间节点。

```
func middleNode(head *ListNode) *ListNode {
	fast := head
	slow := head
	
	for fast != nil {
		plural := false

		for index := 0; index < 2; index++ {
			fast = fast.Next
			if fast == nil {
				if !plural {
					return slow
				}
				return slow.Next
			}
			
			plural = true
		}

		slow = slow.Next
	}

	return nil
}
```

## 两次迭代

第一次迭代先算出链表长度，知道长度后第二次迭代到中间返回即可。

```
func middleNode(head *ListNode) *ListNode {
	i := head
	length := 0
	
	for i != nil {
		i = i.Next
		length = length + 1
	}

	for index := 1; index <= length / 2; index++ {
		head = head.Next
	}

	return head
}
```