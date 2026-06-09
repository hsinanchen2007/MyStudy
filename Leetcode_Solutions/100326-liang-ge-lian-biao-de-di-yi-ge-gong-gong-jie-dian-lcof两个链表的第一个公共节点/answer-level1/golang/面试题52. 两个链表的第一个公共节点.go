### 解题思路
此处撰写解题思路
1.长的先和短的对齐
2.注意是地址相同不是值相同
3.干就完了

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil && headB == nil {
		return nil
	}

	if headA == nil || headB == nil {
		return nil
	}
	nodeA := headA
	nodeB := headB
	countA := 0
	for nodeA != nil {
		countA++
		nodeA = nodeA.Next
	}
	countB := 0
	for nodeB != nil {
		countB++
		nodeB = nodeB.Next
	}

	diff := countA - countB
	//fmt.Println("diff",diff)
	if diff > 0 {
		for diff > 0 {
			diff--
			headA = headA.Next
		}

	} else {
		diff = int(math.Abs(float64(diff)))
		for diff > 0 {
			diff--
			headB = headB.Next
		}
	}

	for headA != nil && headB != nil  {
		if headA != headB {
			headA = headA.Next
			headB = headB.Next
		}else{
			break
		}
	}
	newListNode:=headA
	return  newListNode

}

```