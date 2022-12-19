### 解题思路
换着挺快，就是内存消耗有点大

1、遍历链表，确定顺序
2、m和n，之间的 前后的 val 互换

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	hmap := make([]*ListNode,0)
	for head!=nil{
		hmap = append(hmap,head)
		head=head.Next
	}

	i:= (n-m+1)/2
	j := 0
	
	for i != 0  {
		hmap[m-1+j].Val,hmap[n-1-j].Val = hmap[n-1-j].Val,hmap[m-1+j].Val
		i--
		j++
	}
	
	return hmap[0]
}
```