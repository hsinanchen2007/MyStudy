### 解题思路
多个有序链表，有点类似归并排序的意思

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
    if len(lists) == 0{
        return nil
    }
    if len(lists) ==1{
        return lists[0]
    }

    for len(lists)>1{
        lists = mergeLists(lists)
    }
    return lists[0]
}
func mergeLists(lists []*ListNode)[]*ListNode{
    if len(lists) == 0{
        return lists
    }
    if len(lists) == 1{
        return lists
    }
    left:= 0
    right := len(lists)
    for i:=0;i<(left + right)>>1;i++{
        lists[i] = merge2List(lists[i],lists[len(lists)-1-i])
    }
    return lists[:(left + right+1)>>1]
}
func merge2List(l1,l2 *ListNode) *ListNode {
    if l1 == nil{
        return l2
    }
    if l2 ==nil{
        return l1
    }
    if l1.Val < l2.Val{
        l1.Next= merge2List(l1.Next,l2)
        return l1
    }
    l2.Next = merge2List(l1,l2.Next)
    return l2
}
```