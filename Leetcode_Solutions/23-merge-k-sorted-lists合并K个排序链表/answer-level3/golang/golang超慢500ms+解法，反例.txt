### 解题思路
golang 超慢解法，用时500ms+ 反例中的反例
每次寻找k个链表中最小的那个，加入新的链表
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
	var res  *ListNode= nil
	var q  = res
	var listsNotNull []*ListNode
	for k:= range lists{
		if lists[k]!=nil{
			listsNotNull = append(listsNotNull,lists[k])
		}
	}
    lists = listsNotNull
	for len(lists)>0{
		var min = lists[0]
		var minN = 0
		for k := range lists{
			if lists[k]!=min&&lists[k].Val<=min.Val{
				min = lists[k]
				minN = k
			}
		}
		if res==nil{
			res = min
			q = res
		}else{
			q.Next = min
			q = q.Next
		}
		lists[minN] = min.Next
		if lists[minN]==nil{
			lists = append(lists[:minN],lists[minN+1:]...)
		}
	}
	return res
}


```