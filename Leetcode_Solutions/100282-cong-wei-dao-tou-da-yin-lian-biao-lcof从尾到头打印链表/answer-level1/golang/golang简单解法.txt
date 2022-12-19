### 解题思路
利用栈的思想实现
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
    stack := []int{}
    var list_len int

    for{
        if head == nil {
            break
        }
        list_len++
        stack = append(stack, head.Val);
        head = head.Next
    }

    if list_len == 0 {
        res := []int{}
        return res
    }

    res := []int{}
    for{
        if(len(stack) == 0) {
            break
        }

        res = append(res, stack[len(stack)-1])
        stack = stack[0:len(stack)-1]
    }

    return res
}
```