两数相加（链表表示）
最直观的想法是将AB链表对应的数字分别用变量装起来，进行加法计算后再转换成链表，但这个方法在遇到特别大的整数时就会出现溢出，因为链表可以表示非常多位数的超大整数。
总结的点：（测试用例，边界条件）
排除这个方法后，我们可以想到这是一个类比人类如何进行加法运算的题目，那么就是按位加，并且注意进位。
需要注意两数的加法会出现的各种情况，0 + 1, 1 + 11, 1 + 99
最后，对于需要遍历，并且最后还需要返回头指针的算法，可以采用添加哑节点的方式。

```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	//进位，x，y对应两个链表的某位具体值
	carry := 0
	//哑节点，由它诞生"和链表"
	pre := new(ListNode)
	//游标 -> pre
	cur := pre

	//遍历，按低位->高位
	for l1 != nil || l2 != nil {
		//开始计算，游标往高位移动
		cur.Next = new(ListNode)
		cur = cur.Next

		x, y := 0, 0
		if l1 != nil {
			x = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			y = l2.Val
			l2 = l2.Next
		}

		sum := x + y + carry
		carry  = sum/10 //利用整形除法向下取整的特性
		sum = sum%10

		//此时已经拥有该位的计算结果，可以为游标的当前位赋值
		cur.Val = sum
	}
	//遍历结束后，游标在"和"的最高位，此时判断是否还有进位
	if carry == 1 {
		cur.Next = new(ListNode)
		cur.Next.Val = carry
	}
	//结算完成，pre指向了"和链表"
	return pre.Next
}
```
