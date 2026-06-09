### 解题思路

思路有点傻~ 我想的是如果一定相交的话，那倒过来去遍历 判断是否相等 如果不相等 那当前节点的下一个节点就是相交的节点

### 代码


```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    var a []*ListNode
    var b []*ListNode

    if headA == headB {
        return headA
    }

    for headA != nil{
        a = append(a, headA)
        headA = headA.Next
    }

    for headB != nil{
        b = append(b, headB)
        headB = headB.Next
    }

    var isRef = 0

    var insNode *ListNode
    for len(a) > 0 && len(b) > 0{
        var lastA = a[len(a) - 1]
        var lastB = b[len(b) - 1]
        if (lastA != lastB){
            break
        }else{
            insNode= lastA
            isRef = 1
        }

        a = a[:len(a) - 1]
        b = b[:len(b) - 1]

    }

    if isRef == 1{
        return insNode
    }else{
        return nil
    }

}
```