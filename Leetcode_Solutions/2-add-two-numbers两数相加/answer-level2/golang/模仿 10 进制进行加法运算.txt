### 解题思路
这一题我尝试用暴力解法写过，但是连运行时间都过不去。
暴力写法思路：先将链表转化为可运算的数字，然后将两个数字相加，最后将结果再转化成列表

思考之后发现，其实就是模仿实现了 10 进制相加的操作，只需要将相加的结果判断是否满 10，满 10 进 1 即可，具体思路注释。
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers2(l1 *ListNode, l2 *ListNode) *ListNode {
	// tmp 定义为进制位，标识是否进 1
	tmp := 0
	res := ListNode{}
	// tmpNode 为标志位，标识结果当前操作到哪一步
	tmpNode := &res
	// 遍历 l1 和 l2 链表的所有值，并且每一位都对应做相加
	for l1!=nil || l2 != nil {
		if l1!=nil {
			tmp += l1.Val
			l1 = l1.Next
		}
		if l2 != nil{
			tmp += l2.Val
			l2 = l2.Next
		}
		if tmp >= 10 {
			tmpNode.Val = tmp-10
			tmp = 1
		} else {
			tmpNode.Val = tmp
			tmp = 0
		}
		// 如果 for 循环下一步任然需要继续，则为下一步准备好空位置，并且将 tmpNode 标志指向下一步
		if l1!=nil || l2 != nil {
			next := ListNode{}
			tmpNode.Next = &next
			tmpNode = &next
		}

	}
	// 全部结束之后判断是否需要最终进 1
	if tmp == 1 {
		next := ListNode{Val:1}
		tmpNode.Next = &next
	}
	return &res
}
```