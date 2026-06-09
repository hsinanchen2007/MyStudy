![屏幕快照 2019-07-07 上午2.50.25.png](https://pic.leetcode-cn.com/99127bdcd2d5c9e79b7fa7b66b1825745523ee23712ebd308d94f39f3963e7b0-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-07-07%20%E4%B8%8A%E5%8D%882.50.25.png)

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var tempListNode ListNode
    sum := l1.Val + l2.Val
    y := sum % 10
    z := sum / 10
    tempListNode.Val = y
    tempPointer := &tempListNode
    resultListNode := tempPointer
    for {
        l1Val := 0
        l2Val := 0
        l1hasNext := false
        l2hasNext := false
        if l1.Next != nil {
            l1 = l1.Next
            l1Val = l1.Val
            l1hasNext = true
        }
        if l2.Next != nil {
            l2 = l2.Next
            l2Val = l2.Val
            l2hasNext = true
        }

        if !l1hasNext && !l2hasNext {
            if z == 1 {
                var nextListNode ListNode
                nextListNode.Val = 1
                tempPointer.Next = &nextListNode
            } 
            break
        }
        tempSum := 0
        if sum > 9 {
            tempSum = 1
        }
        sum = l1Val + l2Val + tempSum
        y = sum % 10
        z = sum / 10
        var nextListNode ListNode
        nextListNode.Val = y
        tempPointer.Next = &nextListNode
        tempPointer = tempPointer.Next 
    }
    
    return resultListNode
}
```
