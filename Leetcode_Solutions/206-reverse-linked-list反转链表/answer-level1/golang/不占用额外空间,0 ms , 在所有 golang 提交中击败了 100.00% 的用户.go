### 解题思路
链表反转的口诀
1. 保存前进方向
2. 斩断过去,不忘前事
3. 继续前行

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 链表反转口诀：斩断后路,不忘前事,才能重获新生
func reverseList(head *ListNode) *ListNode {
    var pre *ListNode = nil
    cur := head
    for nil != cur {
        // 1.（保存一下前进方向）保存下一跳
        temp := cur.Next
        // 2.斩断过去,不忘前事
        cur.Next = pre
        // 3.前驱指针的使命在上面已经完成，这里需要更新前驱指针
        pre = cur
        // 当前指针的使命已经完成，需要继续前进了
        cur = temp
    }
    return pre
}
```