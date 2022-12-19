### 解题思路
##### 变量定义：
	判断是否含有重复元素，即需要定义参与比较的两个节点，即新值出现的第一个节点<start> 与 当前节点<curr>进行值比较
	会进行删除操作，即需要定义 <prev>，即start之前的一个节点
	需要记录是否有重复元素，即重复子链表节点中的尾结点<end>

##### 迭代判断：
	如果当前节点和start值相同，则记录有重复节点到end中，继续迭代
	如果当前节点和start值不相同，
		则有两种情况：
			1 end为空，不需要做删除操作，更改start，prev 并继续迭代即可
			2 end不为空，需要做删除操作，即 prev.Next = curr，并且prev不变化，更改start 并继续迭代
##### 特殊判断：
	如果head为nil，单节点，直接返回head
	迭代完成之后，最后仍可能有未删除的元素，需要重新判断end是否为空。





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
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}
	root := &ListNode{Next: head}
	prev := root
	start := head
	var end *ListNode = nil
	for curr := start.Next; curr != nil; curr = curr.Next {
		if curr.Val == start.Val {
			//记录下来，等查找到val变化时，删除
			end = curr
		} else {
			//判断是否需要删除
			if end != nil {
				prev.Next = curr
				end = nil
			} else {
				prev = start
			}
			start = curr
		}
	}
    if end != nil {
       prev.Next = nil 
    }
	return root.Next
}
```