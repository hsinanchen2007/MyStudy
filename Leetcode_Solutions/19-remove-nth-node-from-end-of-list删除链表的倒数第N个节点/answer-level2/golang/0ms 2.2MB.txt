![image.png](https://pic.leetcode-cn.com/851fd75b2b076e1165710d9f49fcdffde8019a8b1ca67854e3a7ecec5b18f4f9-image.png)

### 解题思路
先遍历n个,保证head就是倒数第n个。
再继续遍历，到底，删除这时候的倒数第n个。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if head == nil{
        return nil
    }
    
    iter := head
    idx := 1
    for iter.Next != nil{
        if idx == n{
            break
        }
        idx++
        iter = iter.Next
    }
    lastK := head
    var newHead *ListNode = nil
    for iter.Next!=nil{
        iter = iter.Next
        newHead = lastK
        lastK = lastK.Next
    }

    if newHead == nil{
        return head.Next
    }
    newHead.Next = lastK.Next

    return head
}
```