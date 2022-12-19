### 解题思路
此处撰写解题思路

### 代码

```golang
func hasCycle(head *ListNode) bool {
	fastP, slowP := head, head
	for fastP != nil && fastP.Next != nil  {
		fastP = fastP.Next.Next
		slowP = slowP.Next
		if slowP == fastP{
			return true
		}
	}
	return false
}

```