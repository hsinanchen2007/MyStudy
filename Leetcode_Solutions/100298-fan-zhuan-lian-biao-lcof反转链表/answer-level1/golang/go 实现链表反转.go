解法：



通过双指针，遍历 head 指针，通过中间变量，逐步指向新的 head 节点，完成链表反转



```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }

    var newHead *ListNode
    for head != nil {
        node := head.Next
        head.Next = newHead
        newHead = head
        head = node
    }

    return newHead
}
```



结果如下：

![image-20200225181952102.png](https://pic.leetcode-cn.com/aec22827fdc6d6436622a1f1d6d4ea05eec6dde1497c6c3c216a304c4127db40-image-20200225181952102.png)




还有一种简化的写法，在同一步操作中，改变各个变量对应的值，可以省去中间变量，但这样阅读其实并不友好



```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }

    var newHead *ListNode
    for head != nil {
        head, head.Next,newHead = head.Next, newHead, head
    }

    return newHead
}
```

![image-20200225182106422.png](https://pic.leetcode-cn.com/3ea105a567d04e809baa65eeabda9e96f4cad8dcaf13394b889322e1ba4a6fa5-image-20200225182106422.png)
