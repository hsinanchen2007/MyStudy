
*解法二超越100%golang提交*

## 我的审题思路

    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4

解法：
 首先题目没有说明头节点存不存数据，这是有问题的，下边我的解题以头节点存数据为准。
 1. 显然很容易想到双指针法（三指针法），从前向后遍历取两链表“头部”比较，小者先入新链表

假设第一个节点是存了数据的
```go
type ListNode struct {
	Val int
	Next *ListNode
}
```

## 解法一：三指针法

```go
// 三指针法
// 用三个指针来进行向后扫描
func Sol_1_1(l1, l2 *ListNode) *ListNode {

	// 边界条件（包含了 l1==0 && l2==0 ）
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	var l3 *ListNode	// 返回的链表头指针
	p1, p2 := l1, l2	// l1,l2的两个“头部”指针

	// 先生成l3第一个节点
	if l1.Val <= l2.Val {
		l3 = l1
		p1 = p1.Next
	} else {
		l3 = l2
		p2 = p2.Next
	}

	// 接下来开始向后扫描两个链表的值
	p3 := l3
	for {
		// 有一方先扫完了，就退出循环
		if p1 == nil || p2 == nil {
			break
		}

		// 比较然后填充数据
		if p1.Val <= p2.Val {
			p3.Next = p1
			p3 = p3.Next	// p3后移
			p1 = p1.Next	// p1后移
		} else {
			p3.Next = p2
			p3 = p3.Next
			p2 = p2.Next
		}
		//fmt.Println("测试")
	}

	if p1 != nil {
		// 直接将l1剩余的这些接到l3
		p3.Next = p1
	}
	if p2 != nil {
		// 直接将l2剩余的这些接到l3
		p3.Next = p2
	}

	return l3
}
```

## 解法二： 三指针法/优化连续等值结点

后来经试验题解区高赞答案，没有比该解法更高效的。当然该解法还有些小细节可以优化，就不过多处理。

```go
// 三指针法优化，处理连续相同数字节点
// 对上面解法优化一下：两个链表都会有连续相等值情况，这时直接批量接到l3会更高效：节省了赋值次数和比较次数
// 所以加了两个指针用来记录相同数字开始的地方
// 时间复杂度O(min(m,n)), 空间O(1)
// 208/208 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 97.85 % of golang submissions (2.5 MB)
func Sol_1_2(l1, l2 *ListNode) *ListNode {

	// 边界条件（包含了 l1==0 && l2==0 ）
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	var l3 *ListNode	// 返回的链表头指针
	p1, p2 := l1, l2	// l1,l2的两个“头部”指针, 不断后移

	// 先生成l3第一个节点
	if l1.Val <= l2.Val {
		l3 = l1
		p1 = p1.Next
	} else {
		l3 = l2
		p2 = p2.Next
	}

	// 接下来开始向后扫描两个链表的值
	p3 := l3
	for {
		// 有一方先扫完了，就退出循环
		if p1 == nil || p2 == nil {
			break
		}

		// 现在 p1, p2保证非空
		switch {
		case p1.Val == p2.Val:
			// l1,l2都向后去寻找新数值，并返回新数值的前一个节点
			p3.Next = p1
			p1 = findLarger(p1)		// p1可能后移了
			p3 = p1							// p3此时的next指针非空，但不管，后边会覆盖
			p1 = p1.Next					// p1后移至待比较数值位置
			p3.Next = p2
			p2 = findLarger(p2)
			p3 = p2							// p3此时的next指针非空，但不管，后边会覆盖
			p2 = p2.Next					// p2后移至待比较数值位置
			fmt.Println("11111")

		case p1.Val < p2.Val:
			// l1向后去寻找新数值，并返回新数值的前一个节点
			p3.Next = p1
			p1 = findLarger(p1)
			p3 = p1
			p1 = p1.Next
			fmt.Println("222222")
		case p1.Val > p2.Val:
			// l2向后去寻找新数值，并返回新数值的前一个节点
			p3.Next = p2
			p2 = findLarger(p2)
			p3 = p2
			p2 = p2.Next
			fmt.Println("33333333")
		}

	}

	if p1 != nil {
		// 直接将l1剩余的这些接到l3
		p3.Next = p1
	}
	if p2 != nil {
		// 直接将l2剩余的这些接到l3
		p3.Next = p2
	}

	return l3
}

// 找出更大数之前那个节点
// 3 -> 3 -> 3 -> 5 返回最后那个 3 的节点
// nodeVal为node的值
// 注意传入的p本身就是一份拷贝，绝对不能修改p.Next，只能修改p， 避免破坏原本的链表
func findLarger(p *ListNode) *ListNode {

	for {

		// 有种情况是p已经是末尾
		if p.Next == nil {
			return p
		}

		if p.Next.Val > p.Val {
			break
		}

		// p.Next.Val == p.Val
		p = p.Next
	}
	// 循环结束p就是要求的节点
	return p
}
```

## 解法三： 递归

```go
// -----------------------------------------------------------------------------------
// 暂时想不到继续优化的方向，开始看题解。
// 看了最高赞的两个题解，总共两种方法：递归和迭代。迭代的做法就是我的Sol_1_1.
// 而且有一点注意的是： 其他的题解中所得链表的第一个节点都是无意义的值。好奇怪，那我的思路是怎么通过测试的？

// 那么接下来实现下递归方案
// 我继续按我的思路，所得的链表第一个节点存有意义数值。

// 递归方法
//208/208 cases passed (4 ms)
//Your runtime beats 72.85 % of golang submissions
//Your memory usage beats 68.42 % of golang submissions (2.5 MB)
// 为什么递归明明和Sol_1_1的比较流程看上去一样，但内存占用变多，消耗时间也更多呢？
// 原因在于边界条件这里，如果说Sol_1_1耗时O(min(m+n))，那么这个耗时可能可以算是O(1.5*min(m,n))
// 递归方法每一次递归都要重新判断l1,l2是否为nil
// 不对不对，迭代一样没次都要比较链表是否遍历到尾部，也就是p1,p2是否为nil!
// 希望有知道的能留言为我解惑一二。
func Sol_1_3(l1, l2 *ListNode) *ListNode {

	// 边界条件（包含了 l1==0 && l2==0 ）
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	// 递归
	if l1.Val <= l2.Val {
		l1.Next = Sol_1_3(l1.Next, l2)
		return l1
	} else {
		l2.Next = Sol_1_3(l1, l2.Next)
		return l2
	}
}
```


## 链接

- 博客：<https://eiger.me/post/algo/lt21/>
- Github: <https://github.com/azd1997/Leetcode-training/blob/master/lt21/1.go>