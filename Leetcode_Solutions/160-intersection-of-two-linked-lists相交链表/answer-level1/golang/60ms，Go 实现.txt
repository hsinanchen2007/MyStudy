![image.png](https://pic.leetcode-cn.com/9a0034c2c622d1fdcdff609deebc9579dfc59dee3c199b6716fbfcf0dcb31d3b-image.png)

开两个指针分别遍历这两个链表，在第一次遍历到尾部的时候，指向另一个链表头部继续遍历，这样会抵消长度差。

如果链表有相交，那么会在中途相等，返回相交节点；

如果链表不相交，那么最后会 nil == nil，返回 nil；

代码
```
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    curA,curB := headA,headB
    for curA != curB {      
        if curA == nil {    // 如果第一次遍历到链表尾部，就指向另一个链表的头部，继续遍历，这样会抵消长度差。如果没有相交，因为遍历长度相等，最后会是 nil ==  nil
            curA = headB
        } else {
            curA = curA.Next
        }
        if curB == nil {
            curB = headA
        } else {
            curB = curB.Next
        }
    }
    return curA
}
```