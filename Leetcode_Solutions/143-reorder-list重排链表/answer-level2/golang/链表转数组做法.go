### 解题思路
1. 用数组存储节点
2. 双指针重排数组
3. 重排后的数据进行节点链接成链表

### 代码

```golang
func reorderList(head *ListNode) {
	if head == nil {
		return
	}
	var array []*ListNode
	p := head
	for p != nil {
		array = append(array, p)
		p = p.Next
	}
	result := make([]*ListNode, len(array))
	l, r := 0, len(array)-1
	i := 0
	for l <= r {
		result[i] = array[l]
		l++
		i++
		if l < r {
			result[i] = array[r]
			r--
			i++
		}
	}
	for i := 1; i < len(result); i++ {
		result[i-1].Next = result[i]
		result[i].Next = nil
	}
}
```