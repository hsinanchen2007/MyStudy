两种思路。

1. 一次遍历，使用 O(N) 空间。一上来想到的解决方案，将链表转换成数组，再通过数组长度和 N 找到需要删除的元素的准确位置，再进行删除。

```go []
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if n == 0 {
		return head
	}

	var (
		curNode   = head
        // 将链表每个节点的地址存到内存
		listSlice = make([]*ListNode, 0)
	)

	for curNode != nil {
		listSlice = append(listSlice, curNode)
		curNode = curNode.Next
	}

	length := len(listSlice)
	index := length - n
    // N 超过链表长度
	if index < 0 {
		return head
	}
    // 删除第一个元素
	if index == 0 {
		return head.Next
	}
	lastNode := listSlice[index-1]

    // 删除最后一个元素
	if index == length-1 {
		lastNode.Next = nil
		return head
	}

	nextNode := listSlice[index+1]
	lastNode.Next = nextNode

	return head
}
```

2. 一次遍历，使用 O(1) 空间。看到解答区大神的解答后用 go 写了一遍，加深印象。
该方案

```go []
// 双指针方案
func removeNthFromEndWithDoublePtr(head *ListNode, n int) *ListNode {
    // 添加一个虚拟的头结点
	dumNode := &ListNode{
		Val:  0,
		Next: head,
	}

	var (
        // 双指针
		first, second = dumNode, dumNode
	)

    // 第一个指针向后移动 N 个位置
	for i := 0; i < n; i++ {
        // 如果 N 大于链表长度，直接返回
		if first == nil {
			return head
		}
		first = first.Next
	}

    // 将第一个指针向后移动至最后一个节点
	for first.Next != nil {
		second = second.Next
		first = first.Next
	}

    // 第二个指针所在的节点链到下下个节点
	second.Next = second.Next.Next
	return dumNode.Next
}

```

> 代码还有优化的空间，希望大家能指出来，更希望这块代码对大家有帮助！