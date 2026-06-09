### 解题思路
双指针操作
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA,headB *ListNode)*ListNode{
    nodeA,nodeB:=headA,headB
    for nodeA!=nodeB {
        if nodeA!=nil{
            nodeA=nodeA.Next
        }else{
            nodeA=headB
        }
        if nodeB!=nil{
            nodeB=nodeB.Next
        }else{
            nodeB=headA
        }
    }
    return nodeA
}
```