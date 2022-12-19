```go
//暴力破解法 时间复杂度是O(n*m) 空间复杂度O(1)
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    hb := headB  //这里需要初始化一个临时变量
    for headA != nil {
        for hb != nil {
            if headA == hb {
                return headA
            }
            hb = hb.Next
        }
        headA = headA.Next
        hb = headB  //每循环一次需要重置当前指针位置在链表头
    }
    return nil
}
//路径相等法  时间复杂度是O(n+m), 空间复杂度是O(1)
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    ha := headA
    hb := headB
    for ha != hb {
        if ha == nil {
            ha = headB
        }else{
            ha = ha.Next
        }
        if hb == nil {
            hb = headA
        }else{
            hb = hb.Next
        }
    }
    return ha
}
```
