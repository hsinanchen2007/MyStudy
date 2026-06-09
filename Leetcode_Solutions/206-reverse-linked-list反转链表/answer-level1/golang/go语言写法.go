### 解题思路
具体解释看代码把，中心思想就是每次的next之前是往后的，这次往前就完事儿了。
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
func reverseList(head *ListNode) *ListNode {
    // 首先记住顺序不变还是从左到右，左边依然是pre，右边依然是cur
    // 只不过我们的格式变了，之前是cur的next在后面，现在它的next在前面。
    var prev *ListNode // 注意这里要给prev命名为nil的时候一定要指明它到底是什么类型的nil
    cur := head
    for cur != nil {
       prev,cur,cur.Next =cur,cur.Next ,prev
    }
    return prev
}
```