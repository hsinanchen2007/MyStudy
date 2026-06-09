### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    arr := []int{0}
    result := &ListNode{}
    p1 := l1
    p2 := l2
    p3 := result
    index := 0
    for {
        sum := p1.Val + p2.Val + arr[index]
        if sum >= 10 {
            p3.Val = sum % 10
            arr = append(arr, 1)
        } else {
            p3.Val = sum
            arr = append(arr, 0)
        }
        p3.Next = &ListNode{}

        p1 = p1.Next
        p2 = p2.Next
        if p1 == nil && p2 == nil {
            if sum < 10 {
                p3.Next = nil
            } else {
                p3.Next = &ListNode{
                    Val: 1,
                    Next: nil,
                }
            }
            return result
        }
        if p1 == nil {
            p1 = &ListNode{
                Val: 0,
                Next: nil,
            }
        }
        if p2 == nil {
            p2 = &ListNode{
                Val: 0,
                Next: nil,
            }
        }
        p3 = p3.Next
        index++
    }
    return result
}
```