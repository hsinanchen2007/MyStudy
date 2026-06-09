### 解题思路
递归 通过return 返回追加, 递归虽然写起来简洁,但是 当数据大的时候就不太好了,栈的深度会非常深

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
	if head == nil{
		return nil
	}
	tmp := make([]int,0,1)
	tmp = append(tmp,reversePrint(head.Next)...)
    tmp = append(tmp,head.Val)
	return tmp
}
```

### 解题思路

非递归 执行时间 4ms 内存消耗 3.5MB ,就是简单的循环遍历。

### 代码

``` golang
func reversePrint(head *ListNode) []int {
	tmp := make([]*ListNode,0)
	for head != nil{
		tmp = append(tmp,head)
		head = head.Next
	}
	tmp1 := make([]int,0)
	for i:=len(tmp)-1;i>=0;i--{
		fmt.Println(i)
		tmp1 = append(tmp1, tmp[i].Val)
	}
	return tmp1
}

```

