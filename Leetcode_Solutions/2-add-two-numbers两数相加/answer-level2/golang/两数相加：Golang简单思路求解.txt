思路很简单，通常十进制加法是从右往左加，这个题就是变成了从左往右加。
十进制加法中需要一个标志来表示是否进位，这里使用`add1`这个变量，这个变量只有两个值0或1，因为十进制加法进位要么不进位，要么进位为1。
一开始我们将add1置为0。
然后开始按照题意，开始从左往右加，假设每次循环第一个数和第二个数相加的值分别为n1和n2，注意相加时需要加上`add1`，那么其值为`n1+n2+add1`。如果`n1+n2+add1>=10`，那么需要减去10，然后将`add1`更新为1。
当我们从左往右逐步开加的时候，无非三种情况
1. 第一个数比第二个数长
2. 两个数一样长
3. 第二个数比第一个数长

超长部分的值判断其节点是否为空，为空的话直接+0即可。

```Golang
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    n1 := l1
	n2 := l2
	add1 := 0

	var head = &ListNode{} // 为了循环简单，这里弄个头结点
	preNode := head
	for {
		if n1 == nil && n2 == nil { //当加到最后，判断是否有进1的情况
			if add1 == 1 {
				preNode.Next = &ListNode{1, nil}
			}
			break
		}

		curVal := 0

		if n1 != nil && n2 != nil { //两个数都不为空
			tempSum := n1.Val + n2.Val + add1
			if tempSum >= 10 {
				curVal = tempSum - 10
				add1 = 1
			} else {
				curVal = tempSum
				add1 = 0
			}
		}

		if n1 != nil && n2 == nil { // 第一个数比第二个数位数多
			if n1.Val+0+add1 >= 10 {
				curVal = n1.Val + 0 + add1 - 10
				add1 = 1
			} else {
				curVal = n1.Val + 0 + add1
				add1 = 0
			}
		}

		if n1 == nil && n2 != nil { //第二个数比第一个数位数多
			if n2.Val+0+add1 >= 10 {
				curVal = n2.Val + 0 + add1 - 10
				add1 = 1
			} else {
				curVal = n2.Val + 0 + add1
				add1 = 0
			}
		}
        // 设置当前阶段的值
		curNode := &ListNode{curVal, nil}
		preNode.Next = curNode
		preNode = curNode

		if n1 != nil && n1.Next != nil {
			n1 = n1.Next
		} else { // 这一步很必要，当n1不为空，n1.Next为空时，说明下一位没有数，所以n1要置空，下一次循环忽略该值
			n1 = nil
		}

		if n2 != nil && n2.Next != nil {
			n2 = n2.Next
		} else {
			n2 = nil
		}
	}

	return head.Next
}
```
