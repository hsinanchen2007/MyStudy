## 结果

![image.png](https://pic.leetcode-cn.com/98d11875c73f8b916bdaa3e2231c877046afa584b7400f7f026d909ea1512fa7-image.png)


## 思路

- 由于两个链表都是有序的，使用递归思路实现
- 【开始递归】
- 每一次比较两个链表的头结点，选择值小的节点
- 把选择点的下个节点和另外的节点传递给下一步
- 返回选择的节点
- 【结束递归】

## Code

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }
    if l1.Val < l2.Val {
        l1.Next = mergeTwoLists(l1.Next, l2)
        return l1
    }else {
        l2.Next = mergeTwoLists(l1, l2.Next)
        return l2
    }
}
```
