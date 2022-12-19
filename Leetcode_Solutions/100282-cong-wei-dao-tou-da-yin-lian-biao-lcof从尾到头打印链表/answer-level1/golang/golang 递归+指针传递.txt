### 解题思路
递归 + 指针传递

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

    var arr []int
    reverse(head, &arr)
    return arr
}

func reverse(head *ListNode, arr *[]int) *ListNode {
    if head == nil {
        return nil
    }
    reverse(head.Next, arr)
    *arr = append(*arr, head.Val)
    return head
}
```