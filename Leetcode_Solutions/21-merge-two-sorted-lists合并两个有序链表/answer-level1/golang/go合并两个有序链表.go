算法共分为几步：
1.求两个链表最小值，添加到结果链表，直到一个链表为空；
2.检查l1,l2是不是有链表非空；
3.如果不为空则添加到结果链表；
4.如果都为空则将结果指针的Next为空。
```
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	resHead:=new(ListNode)
	pL1,pL2:=l1,l2
	pRes:=resHead
	for pL1 != nil && pL2 != nil {
		if pL1.Val <= pL2.Val {
			pRes.Next=pL1
			pRes=pRes.Next
			pL1=pL1.Next
		} else {
			pRes.Next=pL2
			pRes=pRes.Next
			pL2=pL2.Next		}
	}
	if pL1!=nil{
		pRes.Next=pL1
	}else{
		if pL2!=nil{
			pRes.Next=pL2
		}else{
			pRes.Next=nil
		}
	}
	return resHead
}
```