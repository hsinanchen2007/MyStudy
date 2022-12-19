### 解题思路
使用了哈希表这种数据结构作为辅助，时间复杂度还是可以哒，就是比较消耗空间
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
// 解法三 使用hash数据结构
func hasCycle(head *ListNode) bool {
    h := make(map[*ListNode]int)
    cur := head
    for cur != nil {
        h[cur]++
        cur = cur.Next
        if h[cur] >1 {
            return true
        }
    }
    
    return false
}
```