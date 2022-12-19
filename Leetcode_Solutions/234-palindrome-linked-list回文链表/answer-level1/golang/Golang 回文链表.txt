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
func isPalindrome(head *ListNode) bool {

        if head == nil {
            return true
        }
        curr := head

        var s []int

        for {
            if curr == nil {
                break
            }
            s = append(s, curr.Val)
            curr = curr.Next
        }

        sl := len(s) - 1
        var j int
        var i int
        for i = sl; j != i && i >= 0; i = i - 1 {
            if s[i] != s[j] {
                return false
            }
            j = j + 1
        }
        return true
    }
```