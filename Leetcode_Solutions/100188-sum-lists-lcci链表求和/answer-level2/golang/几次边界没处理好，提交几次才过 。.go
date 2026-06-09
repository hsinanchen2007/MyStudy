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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
     if l1 == nil {
		return l2
	}
	if l2 == nil{
		return l1
	}
	//1. 计算进位l
	carry := 0
	var p = l1
	var pPre = p
	for ;l1 != nil && l2 != nil; {
		sum := l1.Val + l2.Val + carry
		dev := sum % 10
		l1.Val = dev  //加上上一次的进位
		carry = sum/10
		pPre = l1
		l1 = l1.Next
		l2 = l2.Next
	}

	if l2 != nil{
        //链上链表2
		pPre.Next = l2
		for ;l2 != nil;{
			sum := l2.Val + carry
			dev := sum % 10
			l2.Val = dev
			carry = sum/10
			pPre = l2
			l2 = l2.Next
		}
	}

	for ;l1 != nil;{
		sum := l1.Val + carry
		dev := sum % 10
		l1.Val = dev
		carry = sum/10
		pPre = l1
		l1 = l1.Next
	}

	if carry != 0{
		pPre.Next = &ListNode{carry, nil }
	}

	return p
}
```