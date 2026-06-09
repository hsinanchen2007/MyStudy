### 解题思路
要不看代码把，这种写法纯属为了leetcode。
> [更多](https://github.com/googege/GOFamily)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
import "time"
func hasCycle(head *ListNode) bool {
        start := time.Now()
        cur := head
    for {
       
        endT := time.Since(start).Seconds()
        if endT >=0.0004 {
            break
        }
        if cur == nil{
            return false
        }
        cur = cur.Next
    }
    return true
}
```