### 题解:

- 这是递归反转链表的高级版
- 按照题目要求是必须在原链表操作,不能另起一个链表进行赋值
- 题目且要求是必须进行节点交换,不是把值换掉即可,不然可以把值复制出来,进行转换,然后重新赋值进去!哈哈哈

### 思路:

- 会做这题,必须会知道怎么去反转一个普通的单向链表!必须得先解反转链表
- 然后这题就可以把一个大链表拆分一个个的小链表,然后把各个反转后的小链表连接起来
- 我虽不擅长递归,但还是用递归来解了
- 要注意,每k个遍历,得先把开始的节点保存下来,否则指针已经移动到k个后了...
- 以下是执行详细过程


```
比如链表是 1->2->3->4->5->6->6->7->8->9->10

先递归到最里面,每k个一组,那么就是 1->2->3 4->5->6 7->8->9 10

发现10后面没有了,且10所在的组不够k个,所以10直接返回!

递归开始往回走

7->8->9 一组, 开始反转 

得 9>8->7 , 并把7的next 指向 上面返回的值 也就是 10,然后返回 9所在的地址

递归继续往回走

4->5->6 一组,开始反转

得 6->5->4 , 并把4的next 指向 上面返回的值 也就是 9,然后返回 6所在的地址

递归继续往回走

1->2->3 一组, 开始反转

得 3->2->1 , 并把 1的next 指向 上面返回的值 也就是 6,然后返回3所在的地址

递归结束,返回上面的结果 3

最后打印结果  3->2->1->6->5->4->9->8->7->10
  
```


### 代码:

```go

// 反转一个普通的链表,返回反转后的链表头节点和最后的末尾节点,
func reverse(head *ListNode) (res *ListNode, h *ListNode) {
	if head == nil || head.Next == nil {
		return head,head
	}
	s,h := reverse(head.Next)
    // 这地方有点绕 
	head.Next.Next = head
	head.Next = nil
	return s,head
}

func reverseK(head,ss *ListNode,k int) (res *ListNode) {
    // 定义一个节点=指针移动k个节点的下个节点
	var headN *ListNode
    // 存储一个当前节点,比如 1->2->3 指针已经移动到了3,但是转换的时候 还是得把1传进去
	oldHead := head
	for i:=0;i<k;i++ {
        // 如果正好符合k个,存储下个节点,把当前的指针的next指向nil,防止循环卡死
		if i == k - 1 {
			headN = head.Next
			head.Next = nil
		} else {
			if head != nil && head.Next != nil {// 如果不够k个,且后续还有节点,指针继续往后移动
				head = head.Next
			} else {// 不符合k个且后续没有节点了,直接返回
				return oldHead
			}
		}
	}
    // 递归,ss存储上个 一组数据反转的结果
	ss = reverseK(headN,ss,k)
    // 把小组数据进行反转,并返回反转后 链表的头节点和末尾节点
	s,h := reverse(oldHead)
	if ss == nil { // 如果是递归最里层,把最里层反转的小组的头节点进行赋值
		ss = s
	} else {
		h.Next = ss // 把当前小组的末尾指向上一层反转的头
	}

	return s
}


func reverseKGroup(head *ListNode, k int) *ListNode {
    // 如果 k = 1 ,直接不用反转了
	if k == 1 {
		return head
	}
	return reverseK(head,nil,k)
}
```