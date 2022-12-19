### 解题思路
定义好开头和结尾，开头用个哨兵，结尾负责追加
![QQ20200318-214413@2x.png](https://pic.leetcode-cn.com/065a995ad827a40a349fa0e32e7df95014a18a8f4ec1260480d983e56f6eff2e-QQ20200318-214413@2x.png)


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	// 哨兵，也就是头指针的前缀，为了统一处理头结点
   var preNode = new(ListNode)
	// 尾节点，负责追加数据
	tail := preNode
	for {
		// 当l1遍历完，l2剩下的直接添加上
		if l1 == nil {
			tail.Next = l2
			break
		}
		// 当l2遍历完，l1剩下的直接添加上
		if l2 == nil {
			tail.Next = l1
			break
		}
		// 当l1符合条件，追加元素并且移动
		if l1.Val <= l2.Val {
			tail.Next = l1
			l1 = l1.Next
			tail = tail.Next
		} else { // 当l2符合条件，追加元素并且移动
			tail.Next = l2
			l2 = l2.Next
			tail = tail.Next
		}
	}
	return preNode.Next
}
```