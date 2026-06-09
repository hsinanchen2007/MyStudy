### 解题思路
额，直接暴力解决（太菜了，不会用链表直接操作）

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeDuplicateNodes(head *ListNode) *ListNode {
    if head == nil{
        return head
    }
	var ans = make([]int,0)
	for head !=nil {
		ans = append(ans,head.Val)
		head = head.Next
	}
    var tempAns = make([]int,0)
	var tempMap = make(map[int]int)
	for i:=0;i<len(ans);i++{
		if _, ok := tempMap[ans[i]]; ok {
			continue
		}
        tempAns = append(tempAns,ans[i])
        tempMap[ans[i]]++
	}
    //fmt.Println(tempAns)
	ansNode :=&ListNode{Val:tempAns[0]}
	tail :=ansNode
	for i:=1;i<len(tempAns);i++{
		tail.Next = &ListNode{Val:tempAns[i]}
		tail = tail.Next
	}
	return ansNode
}
```