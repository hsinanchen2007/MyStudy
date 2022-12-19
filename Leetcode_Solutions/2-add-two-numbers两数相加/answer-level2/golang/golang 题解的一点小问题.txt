### 解题思路
思路跟官解一样，不过在使用 go 解的时候，最好还是创建一个头节点，否则当最高两位相加小于10的时候很容易会在高位多出一个 0。  
比如 3->2->1, 3->2->1，最后结果可能会是 6->4->2->0，因为 golang 的结构体一旦赋值，其中所有的数据都会初始化为其每个字段的零值，即使你手动将结构体的实例对象赋值为 nil，最后的结果依然是每个字段的零值。

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
    var sum = new(ListNode)
	head := sum
	var t int
	for l1 !=nil&&l2!=nil{
		sum.Next = new(ListNode)
		sum = sum.Next
        
		sum.Val = (l1.Val+l2.Val+t)%10
		t = (l1.Val+l2.Val+t)/10
		l1, l2 = l1.Next, l2.Next
	}

	for l1!=nil{
		sum.Next = new(ListNode)
		sum = sum.Next

		sum.Val = (l1.Val+t)%10
		t = (l1.Val+t)/10
		l1 = l1.Next
	}

	for l2!=nil{
		sum.Next = new(ListNode)
		sum = sum.Next

		sum.Val = (l2.Val+t)%10
		t = (l2.Val+t)/10
		l2 = l2.Next
	}

	if t!=0{
        sum.Next = new(ListNode)
		sum = sum.Next

		sum.Val = t
	}
	return head.Next
}
```