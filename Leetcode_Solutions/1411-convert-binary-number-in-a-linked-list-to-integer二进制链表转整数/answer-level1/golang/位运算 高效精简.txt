看到评论去有人说为什么不考虑出现负数的情况：
因为题目有说链表最大为30，所以就算按照int为4个字节算的话，也会有32位，
并且现在64位的机器，int基本都是8字节64位，
所以不可能出现负数的情况

```
func getDecimalValue(head *ListNode) int {
    p := head
    res := 0
    for p != nil {
        res = (res << 1) | p.Val
        p = p.Next
    }
    return res
}
```

