

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    	res := &ListNode{}
	iterator := head
	var (
		waitCompareNode *ListNode
	)
	repeat := false
	pre := res
	for iterator != nil {
		if waitCompareNode == nil { // 初始化第一个
			waitCompareNode = iterator
		}else {
			if waitCompareNode.Val == iterator.Val {
				repeat = true
			} else {
				if repeat { // 之前的全部重复 去掉
					repeat = false
				} else {
					pre.Next = waitCompareNode
					pre = pre.Next
				}
				waitCompareNode = iterator
			}
		}
		iterator = iterator.Next
	}
	if waitCompareNode != nil && repeat == false { // 最后一个元素无重复
		pre.Next = waitCompareNode
		pre = pre.Next
	}
	if pre != nil {
		pre.Next = nil
	}
	return res.Next
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/9bd62bb224dbdcf0ae1becf49bb1ce183878548e0e05de2419455596e0755959-image.png)
