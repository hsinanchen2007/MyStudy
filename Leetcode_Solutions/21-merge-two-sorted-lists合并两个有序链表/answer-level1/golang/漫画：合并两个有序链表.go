本题关键之处（完整代码见文末）：

- 使用哨兵节点降低复杂度
- 基本的链表操作

![image.png](https://pic.leetcode-cn.com/41d1a26aa9b61231e071c7dedc6826851999e34f9d05291636107ce0d46dbfd4-image.png)

扩展：其实本题还可以扩展为合并k个有序链表，就需要借助其他的数据结构了。一般而言，我们可以采用最小堆的方式来解题。将K个链表的头节点放入优先队列中，遍历时返回队首元素，并把该队首元素的下一节点放入优先队列中，直至优先队列为空。这个大家有兴趣可以自己下去研究一下。
 
附上本题代码：

```go []
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    prehead := &ListNode{}
    result := prehead
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            prehead.Next = l1
            l1 = l1.Next
        }else{
            prehead.Next = l2
            l2 = l2.Next
        }
        prehead = prehead.Next
    }
    if l1 != nil {
        prehead.Next = l1
    }
    if l2 != nil {
        prehead.Next = l2
    }
    return result.Next
}
```