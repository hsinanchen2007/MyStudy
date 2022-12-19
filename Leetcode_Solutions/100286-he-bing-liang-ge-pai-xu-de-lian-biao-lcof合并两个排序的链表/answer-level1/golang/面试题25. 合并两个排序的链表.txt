### 解题思路
两种方式
1.递归
2.非递归

### 代码

递归：
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	// 如果l1为空 return l2
	if l1 == nil {
		return l2
	// 如果l2为空 return l1
	} else if l2 == nil {
		return l1
	}
	// 如果l1的值小于l2
	if l1.Val < l2.Val {
		l1.Next = mergeTwoLists(l1.Next, l2)
		return l1
	// 如果l1的值大于l2
	} else {
		l2.Next = mergeTwoLists(l2.Next, l1)
		return l2
	}
}
```


递归举例说明
l1 :  1 -> 2 -> 5
l2 :  3 -> 4
total: 1 -> 2 -> 3 -> 4 -> 5

round 1 
l1        			 l2
l1 = l1.next 		
l1 = l1.next           
                     l2 = l2.next
 					 l2 = l2.next
 return l1

// 1->  2->  3 -> 4 -> 5
最终结果:l1.next -> l1.next -> l2.next -> l2.next -> l1
	    


  