本题关键之处（完整代码见文末）：
- 建立哨兵节点，降低题目复杂度
- 采用双指针

![image.png](https://pic.leetcode-cn.com/9c0d3cd8cd70e12abb0b02506da216a059e7209dbed2536581ab0817486ffd3e-image.png)

```go []
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    result := &ListNode{}
    result.Next = head
    var pre *ListNode
    cur := result
    i := 1
    for head != nil {
        if i >= n {
            pre = cur
            cur = cur.Next
        }
        head = head.Next
        i++
    }
    pre.Next = pre.Next.Next
    return result.Next
}
```





