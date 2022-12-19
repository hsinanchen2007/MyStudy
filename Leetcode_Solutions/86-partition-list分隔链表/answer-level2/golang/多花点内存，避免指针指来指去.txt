````
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    if head == nil || head.Next == nil{
        return head
    }
    less:= new(ListNode)
    cur_l := less
    more := new(ListNode)
    cur_m :=more
    cur := head
    for cur !=nil{
        if cur.Val < x {
            cur_l.Next = &ListNode{cur.Val,nil}
            cur_l = cur_l.Next
        }else{
            cur_m.Next = &ListNode{cur.Val,nil}
            cur_m = cur_m.Next
        }
        cur = cur.Next
    }
    cur_l.Next = more.Next
    return less.Next
}