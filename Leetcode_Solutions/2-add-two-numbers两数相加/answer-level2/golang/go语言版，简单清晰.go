## 本题的关键在于：
1.注意不要忘记最后一次相加完还可能存在进位.   
2.两个链表的长度可能不一样.   
3.避免冗长繁琐的代码表达.   
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    l3 := &ListNode{}
    l3.Val = -1
    l3.Next = nil
    var jw int 
    curr := l3
    for l1 != nil || l2 != nil || jw > 0{
        var sum int 
        if l1 !=nil {
            sum += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            sum += l2.Val
            l2 = l2.Next
        }
        if(jw>0){
            sum += jw
        }
        jw = sum/10
        curr.Next = &ListNode{Val:sum%10,Next:nil}
        curr = curr.Next
    }
    return l3.Next
}
```

  
