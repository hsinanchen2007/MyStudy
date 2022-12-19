只会用分治，只会用递归。 哎。 

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0{
        return nil 
    }
    
    return merge(lists,0, len(lists)-1)
    
}

func merge(lists []*ListNode, l, r int) *ListNode {
    if l == r {
        return lists[l]
    }
    m := (l+r)/2
    
    return mergeTwoList(merge(lists, l , m),merge(lists, m+1, r))
    
}

func mergeTwoList(l1,l2 *ListNode) *ListNode{
    if l1 == nil {
        return l2 
    }
    if l2 == nil {
        return l1
    }
    if l1.Val > l2.Val {
        l2.Next = mergeTwoList(l1,l2.Next)
        return l2
    }else {
        l1.Next = mergeTwoList(l1.Next, l2)
        return l1
    }
    
    
    
}
```
