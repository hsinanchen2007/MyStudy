这题在第一次做的时候嫌麻烦，直接用数组解决了，时间百分百，空间百分之五，还是有些不满意的，就用双指针重新写了下，然后来到了双百效率
思路在代码里有提及，就不再详述了，简单说一下这里替换的含义
1->4->3->2->5->2, x = 3
发生替换的时候
p1   p2 p3  
1->4->3->2->5->2
这里怎么替换，就是：
先从原链表里提取出p3，
然后将p3插到p1及p1后面的元素之间，
更新p1，更新p3

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	if head==nil||head.Next==nil {
		return head
	}
	//什么时候需要替换呢？
	//当我找到某个元素p3,p3.Val<x，并且该元素前一个元素p2,且p2的值要>=x
	//这个时候，如果我们有标记位p1,那么:p2->next=p3->next,p3->next=p1->next,p1->next=p3
	//如果没有标记位p1，那么说明head及以后都是>=x的，此时p2->next=p3->next,p3->next=head,p3更新为头节点
	//标记位p1如何找及更新，找：从head开始最后一个<x的即是，更新，每当发生换位，即更新
	var p1,p2,p3 *ListNode
	p3=head
	res:=head
	for p3!=nil{
		if p2!=nil&&p2.Val>=x&&p3.Val<x {
			if p1!=nil {
				p2.Next=p3.Next
				p3.Next=p1.Next
				p1.Next=p3
				//在这种情况下,p3应该发生相应的变化
				p1=p3
				p3=p2.Next
			}else{
				p2.Next=p3.Next
				p3.Next=res
				res=p3
				p1=p3
				p3=p2.Next
			}
		}else{
			if p3.Val<x {
				p1=p3
			}
			p2=p3
			p3=p3.Next
		}
	}
	return res
}
```