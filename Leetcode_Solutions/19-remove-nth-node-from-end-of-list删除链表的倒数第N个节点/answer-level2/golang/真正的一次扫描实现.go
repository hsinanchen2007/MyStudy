官方所说的双指针法，其实还是扫描了两次，只不过是两个指针同时扫描而已。

我选用一个数组来循环保存最后n+1个元素，**真正地**实现一次扫描。

```go
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    // 题目规定“给定的 n 保证是有效的。”所以不对n进行检查了
    var length int = n + 1
    var tempNodes []*ListNode = make([]*ListNode, length)
    var countNode int = 0
    var tail *ListNode = head
    for tail != nil {
        tempNodes[countNode%length] = tail
        tail = tail.Next
        countNode++
    }
    if countNode == n { // 最后一个节点的情况
        return head.Next
    }
    if n == 1 { // 第一个节点的情况
        tempNodes[countNode%length].Next = nil
    } else { // 中间的情况
        tempNodes[countNode%length].Next = tempNodes[(countNode+2)%length]
    }
    return head
}
```

各种解法的时间复杂度看起来都是一样的。

那么为什么要强调一次扫描？我认为是`node.Next`进行跳跃的代价比较大，这种情况下强调**一次扫描**才有意义。而在这种情况下，官方的双指针法并没有达到要求。