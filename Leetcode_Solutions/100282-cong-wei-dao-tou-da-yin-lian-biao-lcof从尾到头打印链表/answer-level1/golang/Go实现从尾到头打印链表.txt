
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
    if head == nil{
        return nil
    }
    res1,res2 := []int{},[]int{}
    
    cur := head
    for cur != nil{
        res1 = append(res1,cur.Val)
        cur = cur.Next
    }
    for i:= len(res1)-1;i>=0;i--{
        res2 = append(res2,res1[i])
    }
    return res2
}
```