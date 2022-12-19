解题思路：
1. 从前到后数k个元素
2. 对子链表进行反转
3. 继续对后续子链进行递归操作
```
func reverseKGroup(head *ListNode, k int) *ListNode {
	pFast:=head
	pSlow:=head
	var count int
	for pFast!=nil{
		count++
		if count==k{
			temp:=pFast.Next
			//翻转pFast至pSlow
			pSlow,pFast=rollingList(pSlow,pFast,k)
			head=pSlow
			pFast.Next=reverseKGroup(temp, k)//递归处理
			return head
		}
		pFast=pFast.Next
	}
	return head
}
func rollingList(head *ListNode,tail *ListNode,k int)(*ListNode,*ListNode){
	var listSli []*ListNode
	pList:=head
	for i:=0;i<k;i++{
		listSli=append(listSli,pList)
		pList=pList.Next
	}
	for i:=k-1;i>0;i--{
		listSli[i].Next=listSli[i-1]
	}
	return tail,head
}
```
