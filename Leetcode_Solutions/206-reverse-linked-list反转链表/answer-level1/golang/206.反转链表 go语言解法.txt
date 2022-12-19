### 解题思路

双指针迭代法，原理如下图：

![7d8712af4fbb870537607b1dd95d66c248eb178db4319919c32d9304ee85b602-迭代.gif](https://pic.leetcode-cn.com/d60bda3f92ade865724b91424000039e8b73d4dc58e55c11a383a9f55ceb09fd-7d8712af4fbb870537607b1dd95d66c248eb178db4319919c32d9304ee85b602-%E8%BF%AD%E4%BB%A3.gif)

图片引用自： leetcode名称为 王尼玛 的用户

### 代码

```golang
func reverseList(head *ListNode) *ListNode {
	var prev *ListNode = nil
	var curr *ListNode = head
	var temp *ListNode
	for curr != nil {
		temp = curr.Next
		curr.Next = prev
		prev = curr
		curr = temp
	}
	return prev
}
```