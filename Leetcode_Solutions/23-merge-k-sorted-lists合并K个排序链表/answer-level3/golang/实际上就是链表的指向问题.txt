### 解题思路
[
  1->4->5,
  1->3->4,
  2->6
]
变成
[
  1->1->3->4->4->5,
  2->6
]
最后变成 1->1->2->3->4->4->5->6
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    listsLen := len(lists)
    if listsLen == 0 {
        return nil
    }
    if listsLen == 1 {
        return lists[0]
    }
    l := new(ListNode)
    ll := l
    for i:=0; i<listsLen-1; i++ {
        l1 := lists[i]
        l2 := lists[i+1]
    
        if i != 0 {
            l1 = l.Next
        }
        for  {
            if l1 == nil {
                ll.Next = l2
                break
            }
            if l2 == nil {
                ll.Next = l1
                break
            }

            if l1.Val < l2.Val {
                ll.Next = l1
                l1 = l1.Next
            }else{
                ll.Next = l2
                l2 = l2.Next
            }
            ll = ll.Next
            
        }
        ll = l
       
    }
    return l.Next
}
```