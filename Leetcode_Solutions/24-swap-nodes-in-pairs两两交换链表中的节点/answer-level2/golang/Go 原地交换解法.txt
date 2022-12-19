算法思路：

 ![WechatIMG1.jpeg](https://pic.leetcode-cn.com/d5d1acc48b06fb02b3d7e9d9ef7cd670591d1f57b7f2a54fec632095903dc050-WechatIMG1.jpeg)

因为交换的是 a2 和 a3, 所以在最开始的时候为 head 添加一个前序节点，最后返回前序节点的下一节点即可，代码如下：

```go
func swapPairs(head *ListNode) *ListNode {
    head = &ListNode{Next: head}
    prev := head
    for prev.Next != nil && prev.Next.Next != nil {
        a1, a2, a3, a4 := prev, prev.Next, prev.Next.Next, prev.Next.Next.Next
        a1.Next, a2.Next, a3.Next = a3, a4, a2
        prev = prev.Next.Next
    }
    return head.Next
}
```