
![image.png](https://pic.leetcode-cn.com/8c35fac3a48aa8a14b5c93eb6cdb254ff52478d2b37a414abc9c7834eaaa6a2c-image.png)

```
func removeElements(head *ListNode, val int) *ListNode {
    var cur,pre *ListNode = head,nil
    for cur != nil {
        if cur.Val == val { // 是要删除的节点
            if pre == nil { // 如果是头节点，那么前移 head 节点
                head = head.Next
                cur = head
            } else {
                pre.Next = cur.Next
                cur = cur.Next
            }
        } else {
            pre = cur
            cur = cur.Next
        }
        
    }
    return head
}
```