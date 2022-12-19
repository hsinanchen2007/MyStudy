### 题解: 
- 对链表进行排序,排序本来不难,可是限制了时间复杂度和空间复杂度
- O(n log n) 时间复杂度和 常数级空间复杂度也就是O(1)

### 思路:
- 翻了下几大经典排序的平均时间复杂度和空间复杂度,发现 希尔排序,归并排序,堆排序符合
- 然后我花了两天,自己操练了下几个排序..
- 最后用 归并排序来解这题
  - 归并排序就是 递归对比两数大小
  - 先把 链表拆分成两段,然后两段再拆两段.. 直到拆到不能拆的时候(就一位)
  - 然后按照递归思想,开始往上返回,依次比较
  - 举例说明吧 
    - 9876543210 先拆  98765, 43210
    - 再递归拆, 987 和 65 
    - 再拆,9和87
    - 9是个数,直接返回,拆8和7,7比8小,那么返回 78
    - 然后递归返回 9 和 78进行比较, 返回 789
    - 递归继续返回 789 和 65的递归结果56进行比较排序,得 56789
    - 另外一边 43210 跟上面一样
    - 最后 56789 与 01234 挨个比较排序返回
    - 最后返回顺序结果

### 代码:

```
func sortList(head *ListNode) *ListNode {
	// 如果 head为空或者head就一位,直接返回
	if head == nil || head.Next == nil {
		return head
	}
	// 定义快慢俩指针,当快指针到末尾的时候,慢指针肯定在链表中间位置
	slow,fast := head,head
	for fast != nil && fast.Next != nil && fast.Next.Next != nil {
		slow,fast = slow.Next,fast.Next.Next
	}
	// 把链表拆分成两段,所以设置中间位置即慢指针的next为nil
	n := slow.Next
	slow.Next = nil
	// 递归排序
	return merge(sortList(head),sortList(n))
}

func merge(node1 *ListNode,node2 *ListNode)*ListNode {
	// 设置一个空链表,
	node := &ListNode{Val:0}
	current := node
	// 挨个比较俩链表的值,把小的值放到新定义的链表里,排好序
	for node1 != nil && node2 != nil {
		if node1.Val <= node2.Val {
			current.Next,node1 = node1,node1.Next
		} else {
			current.Next,node2 = node2,node2.Next
		}
		current = current.Next
	}

	// 两链表可能有一个没走完,所以要把没走完的放到链表的后面
	// 注意,此处跟 数组不一样的是, 数组为什么要循环,因为数组可能一个数组全部走了(比如 12345与6789比较, 前面的全部走完,后面一个没走),另一个可能有多个没走..
	// 链表虽然也有这种可能,但是 node1和node2已经是有序的了,如果另外一个没有走完,直接把next指向node1或者node2就行,因为这是链表
	if node1 != nil {
		current.Next,node1 = node1,node1.Next
	}
	if node2 != nil {
		current.Next,node2 = node2,node2.Next
	}
	return node.Next
}

```