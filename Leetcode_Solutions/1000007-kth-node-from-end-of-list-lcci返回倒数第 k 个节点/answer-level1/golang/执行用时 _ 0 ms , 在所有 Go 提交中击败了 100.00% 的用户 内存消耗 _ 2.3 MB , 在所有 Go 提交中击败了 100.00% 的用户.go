### 解题思路
存到数组里面，通过下标取值

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func kthToLast(head *ListNode, k int) int {
	if head==nil{
		return 0
	}
	emp:=[]int{}
	for e:=head;e!=nil;e=e.Next{
		emp = append(emp,e.Val)
	}
	return emp[len(emp)-k]
}
```