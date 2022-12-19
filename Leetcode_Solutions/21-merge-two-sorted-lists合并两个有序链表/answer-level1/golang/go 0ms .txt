### 解题思路
其实主要思路大家应该都能想到，但在细节处理上有一点需要注意：如何返回头结点
这里可以利用一个空的preHead结点，然后取地址赋值给pre，pre永远指向下一个Node
pre第一次指向的时候就会连带更新preHead的Next为head结点
后续运行过程中pre=pre.Next会自动更新pre
最后返回preHead.Next


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
    preHead := ListNode{}
    pre := &preHead
    for l1 != nil && l2 != nil {
        if l1.Val > l2.Val {
            pre.Next = l2
            l2 = l2.Next
        } else {
            pre.Next = l1
            l1 = l1.Next
        }
        pre = pre.Next
    }
    if l1 != nil {
        pre.Next = l1
    } else {
        pre.Next = l2
    }
    return preHead.Next
}
```