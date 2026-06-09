这道题看到倒数第n个节点我首先想到的就是递归，通过递归来求解链表深度从而根据深度来删除指定节点。
不过使用递归存在一个需要判断起始位置的问题，简单粗暴的在调用函数里直接判断处理了，另外附上弟弟代码

```go
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil || head.Next == nil {
		return nil
	}
	depth := traversal(head, n)
	if depth == n {
		head = head.Next
	}
	return head
}

func traversal(head *ListNode, n int) int {
	if head.Next == nil {
		return 1
	}
	depth := traversal(head.Next, n) + 1
	if depth == n+1 {
		head.Next = head.Next.Next
	}
	return depth
}
```

递归的效率也还算可以：
![Jietu20200214-002850@2x.jpg](https://pic.leetcode-cn.com/1cdb02ad60d7347f04071614a74c66d063cf0ff3d41f5834bf9ea05c55a77fff-Jietu20200214-002850@2x.jpg)


