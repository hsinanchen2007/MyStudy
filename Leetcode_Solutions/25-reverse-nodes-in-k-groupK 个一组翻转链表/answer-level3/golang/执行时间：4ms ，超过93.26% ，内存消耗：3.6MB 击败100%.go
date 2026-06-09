### 解题思路
此处撰写解题思路
菜鸟笔记，大神们多多指教
1、利用两个指针始终保持着K个节点的距离，并且left的指针始终指向需要翻转部分的第一个节点；
2、为了使left和right指针中间保持着需要反序的节点，需要让right移动k个节点，然后left和right
再同时移动;
3、right指针始终为翻转部分的下个节点，这样的话，right就不会被节点的反序操作而影响自身的遍历；
4、每次right移动k个节点后，就可以对处于left和right之间的节点做一次翻转操作，移动的距离使用一个
变量count计数；
5、将一部分节点翻转，然后返回新的头节点newHead，再将left重新指向新的头节点，使翻转后的部分
重新回到原始链表中；
6、特殊情况，k为1时不需要反序，k为链表总长度时，right因为没有在翻转部分，所以会出链表为空，当
这种情况发现的时候正好，count == k,直接调用翻转方法即可。
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	if k == 1{
		return  head
	}
	virtualHead := &ListNode{0,nil}//创建一个虚拟的头指针
	virtualHead.Next = head
	left := virtualHead//第二个指针
	right := head//第一个移动的指针
	startFlag := false //left指针开始移动的标志
	count := 0 //对移动单位计数
	for right != nil{
		if count==k{
			count = 0
			startFlag = true
			left.Next = reverseKg(left.Next,k)
		}
		right = right.Next
		count++
		if startFlag {
			left = left.Next
		}
	}
	if count == k{
		left.Next = reverseKg(left.Next,k)
	}
	return  virtualHead.Next
}

func reverseKg(head *ListNode,k int) *ListNode{
	count := 1
	p := head.Next
	first := head
	var two *ListNode
	for  count < k{
		two = p
		if p != nil{
			p = p.Next
		}else{
			break
		}
		count++
		two.Next = first
		first = two
	}
	head.Next = p
	return two
}
```