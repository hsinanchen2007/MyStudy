1. 如何实现两个长度不同的链表尾部对齐?
   计算链表长度作为,递归的深度,通过深度控制是否next指针
2. 还有什么方法?
   1. 最简单的方式是 将链表反转然后直接遍历.
   2. 在不引起副作用的前提下,递归方法也可以改进成双栈实现.
3. 从中学到什么?
   对于此题,双栈实现要比递归实现简单易懂,可见 如果递归理顺不清,可以从辅助栈的思路来思考,这对限制时间的思考,较为有用。

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var d1,d2 int
    a,b := l1,l2
    for a != nil{
        d1 ++
        a = a.Next
    }
    for b != nil{
        d2 ++
        b = b.Next
    }
    res,c:= addTwoNumbers2(l1,l2,d1,d2)
    if c > 0{
        return &ListNode{Val:c,Next:res}
    }
    return res
} 
func addTwoNumbers2(l1,l2 *ListNode,d1,d2 int )(res *ListNode,c int){
        if l1 != nil && l2 != nil{
            if l1.Next == nil && l2.Next == nil{
                n := l1.Val + l2.Val
                c = n / 10
                res = &ListNode{Val:n % 10,Next:nil}
                return
            }
        }
        var a *ListNode
        var b,n int
        if d1 > d2{
            a, b = addTwoNumbers2(l1.Next,l2,d1-1,d2)
            n = l1.Val + b
        }else if d1 < d2{
            a, b = addTwoNumbers2(l1,l2.Next,d1,d2-1)
            n = l2.Val + b
        }else{
            a, b = addTwoNumbers2(l1.Next,l2.Next,d1-1,d2-1)
            n = b + l1.Val + l2.Val
        }
        res = &ListNode{Val:n % 10,Next:a}
        c = n / 10
        return 
}
```
