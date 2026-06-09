
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
    var minList int
    var minVal = math.MaxInt32
    var result *ListNode
    // 每趟处理每个数组头节点里最小的那个    
    for i:=0;i<len(lists);i++{
        if lists[i] != nil {
            if lists[i].Val < minVal{
                minList = i
                minVal = lists[i].Val
            }
        }else {
            // 一旦发现数字里的链表有空了，就把它移除
            if i+1 < len(lists){
                lists = append(lists[:i],lists[i+1:]...)
                // 重置 i
                i--
            }else{
                lists = lists[:i]
            }
            
        }
    }
    if len(lists) == 0{
        return nil
    }
    if len(lists) == 1 {
        return lists[0]
    }
    // 将最小的那个链表向下挪一位
    lists[minList] = lists[minList].Next
    result = &ListNode{Val:minVal}
    result.Next = mergeKLists(lists)
    return result
}
```