首先速览一遍题目，可以想到设置步长为2，循环解题。其实有一种我解链表题的小trick，就是前置指针永远比后置指针好用。
这道题我们就利用构造一个指向head的前置指针解题。
所有代码如下
```
func swapPairs(head *ListNode) *ListNode {
    var prev *ListNode = &ListNode{0, head}
    var hint *ListNode = prev
    for prev.Next != nil && prev.Next.Next != nil {
        prev.Next.Next.Next, prev.Next.Next, prev.Next, prev = prev.Next, prev.Next.Next.Next, prev.Next.Next, prev.Next
    }
    return hint.Next
}
```



逐行解析：
`var prev *ListNode = &ListNode{0, head}` 构造指向head的prev指针
`var hint *ListNode = prev` 因为prev指针需要移动，留存一个backup

```
    for prev.Next != nil && prev.Next.Next != nil {
        prev.Next.Next.Next, prev.Next.Next, prev.Next, prev = prev.Next, prev.Next.Next.Next, prev.Next.Next, prev.Next
    }
``` 
重点代码，由于golang与python的等号赋值的特殊性，我们可以一行代码完成整个交换过程
这一行代码做了4件事，以prev->1->2->3->4->nil为例
1. prev.Next 也就是1，赋值给2的下一个元素，也就是把2接在1的后面
2. 把2的下一个元素，也就是3，赋值给1的下一个元素，也就是把1接到3后面
3. 把1的下一个元素，也就是2，赋值给prev的下一个元素，因为2和1已经调换顺序，需要把prev重新连接到2的前面
4. 把prev的下一个元素，也就是1，赋值给prev。注意！这里的prev还没有发生改变，这一行是同时生效，所以现在prev的下一个元素还是1，所以看似把prev.Next赋值给了prev是一跳，其实是两跳！因为1和2换了位置，我们又跳到了1，所以是两跳。

最后，出循环的条件是，prev的下一个不是空，并且下下个也不是空值。我们可以发现，思路就是，通过prev指针长了个长胳膊，调换他的下一个和下下个元素，而不是利用三个指针来完成。思路清晰，代码量少，0ms速度，2.1M内存，写法比较优雅。自己觉得写的算是挺完美的一题，欢迎讨论~