### 题解:

- 两条链表可能会相交!
- 对于示例的参数别看了. 跟题目没有关系的,只是为了解释测试用例的参数是啥意思而已!如果自己本地测试,用不着的!

### 思路:

- 由于题目要求 时间复杂度是 O(n), 空间复杂度是 O(1),不然可以做用作弊法,就是把数据放到map里,然后看是否存在...
- 我第一反应的做法:
  - 先分别算出A B 链表长度 `aLen`,`bLen`
  - 如果 A比B长,那么让A先移动 `aLen - bLen` 步, 类似 示例1里,B先走,走到0位置,如果B比A长,一样做法,让长的先走 长多少步
  - 然后 同时走,如果相同那么相交点了,如果走到nil,那么就是走到最后了!
  - 算一下时间复杂度, 取长度 `O(n) + O(n)`, 先移动 `|aLen - bLen|` 步, 时间复杂度也是 `O(n)`, 最后一起移动,时间复杂度也是 `O(n)`
  - 那么时间复杂度是 `4*O(n)`,所以符合条件,时间复杂度就是 `O(n)`,没有用额外空间,所以空间复杂度还是 `O(1)`
- 另外一种思路:
  - A和B同时走,当A走到末尾的时间,开始走B,同理,当B走到末尾的时候,开始走A, 那么如果相交,肯定会同时走到一个相同的点
  ![相交链表](https://pic.leetcode-cn.com/d7367b1b2177c838181f7914002f81a38fdd9f3369c28df4507d9ed55dea444f-file_1568111729580)
  - 为什么这么说呢, 看图中c1 是相交点, 假设 `a1到c1的距离是x`, `b1到c1的距离是y`,`公共链表 c1到 c3 是 z`
  - A和B同时出发, 当A到达c3的时候,B还在 c3前面`(y-x)`的位置,然后 A开始走B的路线,等B到了末尾,开始走A的路线
  - 因为第一次的时候, A比B到结尾c3快 `(y-x)`,当第二圈的时候,A走的是B的距离,就慢了,慢了 `(y-x)`,所以当第二圈的时候,B会在c1位置追上A
  - 仔细想一下,就是 `x + y + z = y + x + z`,最开始相遇的点就是c1位置,因为c2,c3都是相遇的!只是最早的是 c1
  

### 代码:

- 简单的解法

```
func getIntersectionNode2(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	
	// 分别取A和B的长度
	aLen := nodeLen(headA)
	bLen := nodeLen(headB)

	if aLen > bLen {
		// 如果A比B长,A先移动 a-b 长度的距离
		for i:=0;i<aLen - bLen;i++ {
			headA = headA.Next
		}
	} else {
		// 如果B比A长, B先移动 b-a 长度的距离
		for i:=0;i<bLen-aLen;i++ {
			headB = headB.Next
		}
	}

	// 遍历一个
	for headA != nil {
		// 如果相等,那么相遇了,返回
		if headA  == headB {
			return headA
		}
		// 每次同时都移动一个节点
		headA = headA.Next
		headB = headB.Next
	}

	return nil
}

func nodeLen(head *ListNode) int {
	var i int
	for head != nil {
		i++
		head = head.Next
	}
	return i
}
```

- 第二种解法

```
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	// 如果链表为空,直接返回
	if headA == nil || headB == nil {
		return nil
	}
	// 设置两个临时链表
	nodeA := headA
	nodeB := headB
	// 定义两个参数,方便参考是否重新赋值了
	var m,n int
	for true {
		// 如果相遇了,直接返回
		if nodeA == nodeB {
			return nodeA
		}
		// 两链表都移动一个节点
		nodeA = nodeA.Next
		nodeB = nodeB.Next

		// 如果A节点走到了最后
		if nodeA == nil {
			if m == 0 {// 如果是第一次走到最后,把B赋值给A,且标记一下
				nodeA = headB
				m++
			} else { // 如果不是第一次了,那么说明没有相遇,返回nil
				return nil
			}
		}

		// 如果B节点走到了最后
		if nodeB == nil {
			if n == 0 {// 如果是第一次走到最后,把A赋值给B,且标记一下
				nodeB = headA
				n++
			} else { // 如果不是第一次了,那么说明没有相遇,返回nil
				return nil
			}
		}
	}

	return nil
}
```