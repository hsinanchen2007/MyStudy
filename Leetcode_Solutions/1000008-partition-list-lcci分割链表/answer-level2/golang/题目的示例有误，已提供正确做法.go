### 解题思路

Go: 0ms(100%), 2.4MB(100%)

首先说明：题目提供的示例输出与实际运行的输出不符
![image.png](https://pic.leetcode-cn.com/27e656ad0d3fc4cd78d108e978770a27db3e216869e3f679865d92e66a465cd9-image.png)

在说正确的输出之前需要先说说思路：遍历链表，将链表中所有小于x的节点抽离出来，通过**头插法**构造新链表，然后将该新链表连接到已被处理过的原链表左边。**实际的运行结果就是使用头插法构造节点值小于x的链表然后连接到原链表的左边**，详见代码


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    nilHead := new(ListNode)
    nilHead.Next = head
    pre := nilHead
    var lessHead, lessTail *ListNode
    for pre.Next != nil {
        if pre.Next.Val < x {
            less := pre.Next
            pre.Next = less.Next
            less.Next = nil
            if lessTail == nil {
                lessTail, lessHead = less, less
            } else {
                // 头插法：按照实际运行结果，此处采用的是头插法
                less.Next = lessHead
                lessHead = less
            }
        } else {
            pre = pre.Next
        }
    }

    if lessHead == nil {
        return nilHead.Next
    } else {
        lessTail.Next = nilHead.Next
        return lessHead
    }
}
```