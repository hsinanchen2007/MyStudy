### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
*/

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1==nil{
		return l2
	}else if l2==nil{
		return l1
	}
	var res *ListNode
	var p *ListNode
	if l1.Val>l2.Val{
		res = l2
		l2 = l2.Next
	}else{
		res = l1
		l1 = l1.Next
	}
	p = res
	for l1!=nil&&l2!=nil {
		if l1.Val <=l2.Val{

			var _l1 = l1
			l1 = l1.Next
			p.Next = _l1
			p = p.Next

			for l1!=nil&&l1.Val<=l2.Val{
				p.Next = l1
				p = p.Next
				l1 = l1.Next
			}

			p.Next =l2
			p = p.Next
			l2 = l2.Next
		}else {
			var _l2 = l2
			l2 = l2.Next
			p.Next = _l2
			p = p.Next

			for l2!=nil&&l2.Val<=l1.Val{
				p.Next = l2
				p = p.Next
				l2 = l2.Next
			}

			p.Next =l1
			p = p.Next
			l1 = l1.Next
		}
	}
	if l1==nil&&l2!=nil{
		for l2!=nil{
			p.Next = l2
			p = p.Next
			l2 = l2.Next
		}
	}else if l2==nil&&l1!=nil{
		for l1!=nil{
			p.Next = l1
			p  =p.Next
			l1 = l1.Next
		}
	}

	return res;
}


```