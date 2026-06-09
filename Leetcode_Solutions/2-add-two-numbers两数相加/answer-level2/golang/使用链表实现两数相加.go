### 解题思路
本题较为简单，给你的次序是逆序的，直接按位相加即可
大致流程：
1. 遍历整个链表，直到最长的那个链表被遍历完。如果遍历过程中，其中一个链表==nil，把它的Val看作是0即可
2. 方便起见，创建一条新的链表来储存相加结果。每次遍历都创建一个新节点


需要注意的点是：
1. 判空，所给的链表可能是有一个是空的
2. 考虑进位，并且把进位条件 isMore==1放到循环条件中，防止因进位而需要额外产生新节点
3. 需要返回result.Next，去掉无数据的链表头

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
	result:=new(ListNode)
	cursor:=result
	isMore:=0 //是否进位
	if l1==nil{
		return l2
	}
	if l2==nil{
		return l1
	}

	for (l1!=nil||l2!=nil)||isMore==1{
		//初始化新节点
		currentNode:=new(ListNode)
		//找出两个链表节点的值
		var v1,v2 int

		if l1!=nil{
			v1=l1.Val
			l1=l1.Next
		}else{
			v1=0
		}

		if l2!=nil{
			v2=l2.Val
			l2=l2.Next
		}else{
			v2=0
		}


		//节点赋值
		currentNode.Val=(v1+v2+isMore)%10

		//节点链接
		cursor.Next=currentNode
		cursor=currentNode

		isMore=(v1+v2+isMore)/10
	}

	return result.Next
}
```