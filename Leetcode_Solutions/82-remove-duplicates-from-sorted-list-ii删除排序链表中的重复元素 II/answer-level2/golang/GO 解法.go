![image.png](https://pic.leetcode-cn.com/42a7546731195dda39bdebad4cd856f6dd70825beef1323a9f4d68428774abe3-image.png)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {

    // ?  1  2  3  3  4  4  5
    //       p1 h  p2
    // p0

    // ?  1  2  4  4  5
    // p1 h  p2
    // p0

    // ?  1  2  4  4  5
    //       p1 h  p2
    // p0

    // ?  1  2  5
    //       p1 h  p2
    // p0

    // return p0.Next

    p1 := &ListNode{
        Next: head,
    }

    p0 := p1
    p2 := &ListNode{}

    for head != nil && head.Next != nil {
        // current == next
        if head.Val == head.Next.Val {
            // p2 record the next node.
            p2 = head.Next

            for {
                // Find the p2 is not the same as p2.Next.
                if p2.Next == nil || p2.Val != p2.Next.Val {
                    // Remove node in (p1, p2].
                    p1.Next = p2.Next

                    // The head is p1 now.
                    head = p2.Next
                    break
                }

                p2 = p2.Next
            }
        } else {
            p1 = head
            head = head.Next
        }
    }

    return p0.Next
}
```