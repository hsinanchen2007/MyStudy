**代码**

```
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil{
	    return l2
	}
	if l2 == nil{
		return l1	
    }
    var result = new(ListNode)
	var resultPoint =  result
	var temp = new(ListNode)
	for l1 != nil && l2 != nil{
        if l1.Val < l2.Val{
			temp = l1
			l1 = l1.Next
		}else{
			temp = l2
			l2 = l2.Next
		}
		resultPoint.Next = temp
		resultPoint = resultPoint.Next
	}
	if l1 != nil{
		resultPoint.Next = l1
		resultPoint = resultPoint.Next
	}
	if l2 != nil{
		resultPoint.Next = l2
		resultPoint = resultPoint.Next
	}
	return result.Next
}
```
