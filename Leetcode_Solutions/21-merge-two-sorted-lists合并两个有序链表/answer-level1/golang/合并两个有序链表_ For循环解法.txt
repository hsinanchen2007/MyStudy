# 用For循环的方式来解题，没有用递归

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    
    // 边界条件检查
    if l1 == nil {
        return l2
    } else if l2 == nil {
        return l1
    }
    
    // 创建一个新的链表，用来接收结果
    newList := &ListNode{}
    
    // 链表指针，一开始指向newList
    currList := newList
    
    for {
        // 连接l1的Node还是l2的，这里分为5种情况
        linkL1 := false
        if (l1 == nil && l2 == nil) { // 1. l1和l2都为空，退出循环
            break
        } else if (l1 == nil && l2 != nil) { // 2. l1为空，l2不为空，连接l2
            linkL1 = false
        } else if (l1 != nil && l2 == nil) { // 3. l1不为空，l2为空，连接l1
            linkL1 = true
        } else if (l1.Val < l2.Val) { // 4. l1的值小于l2的，连接l1
            linkL1 = true
        } else { // 5. 连接l2
            linkL1 = false
        }
        
        // 开始连接Node，并移动指针
        if linkL1 {
            currList.Val = l1.Val
            l1 = l1.Next
        } else {
            currList.Val = l2.Val
            l2 = l2.Next
        }
        
        // 如果l1或者l2下一个Node还有的话，就创建一个新的Node，准备连接下一个Node
        if (l1 != nil || l2 != nil) {
            currList.Next = &ListNode{}
            currList = currList.Next
        }

    }
    
    return newList
}
```
