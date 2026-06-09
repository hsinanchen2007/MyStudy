### 解题思路
非递归代码

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    
    result := &ListNode{}
    p := result
    numTen := 0
    for{ 
        if l1 == nil && l2 == nil {
            break
        }else if l1 == nil && l2 !=nil{
            newItem := &ListNode{}

            num := l2.Val + numTen
            if num < 10 {
                newItem.Val = num 
                numTen = 0
            }else{
                newItem.Val = num % 10
                numTen = 1
            }

            p.Next = newItem
            p = p.Next

            l2 = l2.Next

        }else if l1 != nil && l2 ==nil{
            newItem := &ListNode{}
            
            num := l1.Val + numTen
            if num < 10 {
                newItem.Val = num 
                numTen = 0
            }else{
                newItem.Val = num % 10
                numTen = 1
            }

            p.Next = newItem
            p = p.Next

            l1 = l1.Next
        }else {

            newItem := &ListNode{}
            num := l1.Val + l2.Val + numTen
            if num < 10 {
                newItem.Val = num 
                numTen = 0
            }else{
                newItem.Val = num % 10
                numTen = 1
            }

            p.Next = newItem
            p = p.Next

            l1 = l1.Next
            l2 = l2.Next
        }
    }

    if numTen !=0 {
        newItem := &ListNode{Val:numTen,}
        p.Next = newItem
        p = p.Next
    }

    return result.Next
}
```