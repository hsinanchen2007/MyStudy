### 解题思路
递归实现

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
    if head == nil {
        return nil
    }
    if head.Next == nil {
        var ret []int
        ret = append(ret, head.Val)
        return ret
    }

    return append(reversePrint(head.Next), head.Val)
}
```