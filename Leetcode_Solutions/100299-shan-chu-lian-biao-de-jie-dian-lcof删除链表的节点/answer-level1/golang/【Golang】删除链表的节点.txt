# 代码

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(head *ListNode, val int) *ListNode {
    //情况1
    if head.Val==val{
        return head.Next
    }
    //情况2
    pre:=head   
    for head.Next.Val!=val{
        head=head.Next
    }
    head.Next=head.Next.Next
    return pre
}
```

# 解题思路

**情况1：要删除的节点为头节点，直接返回后面的链表head.Next即可**

**情况2：**
**设置pre来保存前面的节点，再遍历链表，直到找到要删除的节点后跳出循环，将head.Next指定为该节点的下一个链表即可，即head.Next=head.Next.Next。**

---

下面用一张自制的图片来简单表示这种思路

![删除节点链表png.png](https://pic.leetcode-cn.com/dfe48f0f213dc46764d25635d97ae9b4abf6fa307869643cb214baab3ef859ae-%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9%E9%93%BE%E8%A1%A8png.png)
