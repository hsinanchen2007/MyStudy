### 解题思路
递归遍历即可, 终止条件是遍历到了最后一个节点.

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
    var result []int
    if head == nil {return result}
    if head.Next == nil {
        return append(result, head.Val)
    }
    result = append(result, reversePrint(head.Next)...)
    result = append(result, head.Val)
    
    return result
}
```