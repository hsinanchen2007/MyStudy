### 解题思路
写法一：顺序两两合并
	执行用时 :124 ms, 在所有 Go 提交中击败了27.04% 的用户
	内存消耗 :5.3 MB, 在所有 Go 提交中击败了88.10%的用户

写法二：分治写法，无case 2的判断
	执行用时 :16 ms, 在所有 Go 提交中击败了57.20% 的用户
	内存消耗 :5.3 MB, 在所有 Go 提交中击败了88.10%的用户

写法二优化：分治写法，有case 2的判断
	执行用时 :8 ms, 在所有 Go 提交中击败了96.56% 的用户
	内存消耗 :5.3 MB, 在所有 Go 提交中击败了100.00%的用户

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeKLists(lists []*ListNode) *ListNode {
	/* 按顺序两两合并
	var res *ListNode
	for i := 0; i < len(lists); i++ {
		res = mergeTwoLists(res, lists[i])
	}
	return res
	*/
	// 分治递归
	switch len(lists) {
	case 0:
		return nil
	case 1:
		return lists[0]
	case 2:
		return mergeTwoLists(lists[0], lists[1]) //可以合并到default，单拎出来效率更高
	default:
		mid := (len(lists) + 1) >> 1 //折半两分
		return mergeTwoLists(mergeKLists(lists[:mid]), mergeKLists(lists[mid:]))
	}
}

//21题合并两个有序链表的方法直接搬过来
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{} 
	cursor := head
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cursor.Next = l1
			l1 = l1.Next
		} else {
			cursor.Next = l2
			l2 = l2.Next
		}
		cursor = cursor.Next
	}
	if l1 == nil {
		cursor.Next = l2
	} else {
		cursor.Next = l1
	}
	return head.Next
}

```