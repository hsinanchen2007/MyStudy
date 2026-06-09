### 解题思路
#### 迭代
1、先用临时变量保存Next节点
2、把当前节点的Next节点指向ret
3、再把当前节点赋值给ret
4、最后把第一步的临时变量赋值给当前节点

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var ret *ListNode
    for head != nil {
        next := head.Next
        head.Next = ret
        ret = head
        head = next
    }
    return ret
}
```