# 方法一：数组排序

链表无法直接排序，但是数组或者slice是可以直接排序的，所以可以将链表转换成slice以后，用内置接口将slice排序，然后再将slice转换回链表，即可输出答案
时间复杂度: O(n)，n为节点个数
空间复杂度: O(n)
```go
func sortList(head *ListNode) *ListNode {
	// 将链表转换成slice
	nums := make([]int, 0)
	tmp := head
	for tmp != nil {
		nums = append(nums, tmp.Val)
		tmp = tmp.Next
	}
	// 将slice排序
	sort.Ints(nums)
	// 将slice转换成链表
	dummyHead := new(ListNode)
	node := dummyHead
	for i := 0; i < len(nums); i++ {
		tmpNode := &ListNode{nums[i], nil}
		node.Next = tmpNode
		node = tmpNode
	}
	return dummyHead.Next
}
```

# 方法二：归并排序（自底向上）

首先，从链表上一次切一个元素下来为一组，相邻两组排序以后合并，形成新链表
然后，从链表上一次切两个元素下来为一组，相邻两组排序以后合并，因为上一步中已经将元素两两排序，所以切下的每组元素内部肯定是有序的，所以能合并成一个大的有序链表，输出新链表
继续这个步骤，直到整个链表都被排序
以4->2->1->3为例
step = 1时，切下来两组为4->nil, 2->nil，剩下的链表为1->3->nil，合并以后更新链表为2->4->nil；继续处理剩下的链表，切下来的两组为1->nil，3->nil，合并以后为1->3->nil，和前面的结果合并以后为2->
step = 2时，切下来的两组为2->4->nil，1->3->nil，合并以后为1->2->3->4->nil
step = 4时，不满足step < length，结束并返回结果
要实现上述流程，需要实现两个接口
一是cut，输入链表头head和需要cut的个数n，会从输入链表中cut掉n个，返回cut后剩下的链表的链表头，此时输入的head指向cut下来的长度为n的链表
二是merge，将两个链表有序合成一个链表，输入两个链表的表头，输出合成以后的链表的链表头和链表尾
时间复杂度: O(nlogn)，n为节点个数。为O(nlogn)的原因是在归并排序方法中，一共有logn个step，每个step都需要将n个元素全部遍历一遍，所以是nlogn
空间复杂度: O(1)
```go
func cut(head *ListNode, n int) *ListNode {
	var newRoot *ListNode
	node := head
	for i := 0; i < n; i++ {
		if node != nil {
			if i == n - 1 {
				newRoot = node.Next
				node.Next = nil
			} else {
				node = node.Next
			}
		}
	}
	return newRoot
}

func merge(l1 *ListNode, l2 *ListNode) (*ListNode, *ListNode) {
    node1 := l1
    node2 := l2
    dummyHead := new(ListNode)
    tail := dummyHead
    for !(node1 == nil && node2 == nil) {
        if node2 == nil || (node1 != nil && node2 != nil && node1.Val <= node2.Val) {
            tail.Next = node1
            tail = node1
            node1 = node1.Next
        } else if node1 == nil || (node1 != nil && node2 != nil && node2.Val < node1.Val)  {
            tail.Next = node2
            tail = node2
            node2 = node2.Next
        }
    }
    tail.Next = nil
    return dummyHead.Next, tail
}

func sortList(head *ListNode) *ListNode {
	dummyHead := new(ListNode)
	dummyHead.Next = head
	node := head
	length := 0
	for node != nil {
		node = node.Next
		length++
	}
	for step := 1; step < length; step *= 2 {
		cur := dummyHead.Next
		tail := dummyHead
		for cur != nil {
			left := cur
			right := cut(cur, step)
			cur = cut(right, step)
			tail.Next, tail = merge(left, right)
		}
	}
	return dummyHead.Next
}
```