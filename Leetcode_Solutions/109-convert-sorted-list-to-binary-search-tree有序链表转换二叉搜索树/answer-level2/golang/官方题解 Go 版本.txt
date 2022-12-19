# 递归
```golang
func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	mid := findMiddle(head) //find root
	node := &TreeNode{
		Val: mid.Val,
	}

	if head == mid { //just one element
		return node
	}

	node.Left = sortedListToBST(head)
	node.Right = sortedListToBST(mid.Next)
	return node
}

func findMiddle(node *ListNode) *ListNode {
	var prev *ListNode
	slow, fast := node, node
	for fast != nil && fast.Next != nil { //end or end.Next
		prev = slow
		slow = slow.Next      //move 1
		fast = fast.Next.Next //move 2
	}

	if prev != nil {
		prev.Next = nil
	}
	return slow // = length/2 + 1
	//1=>1
	//2=>2
	//3=>2
	//4=>3
	//5=>3
	//6=>4
	//7=>4
}
```


# 数组
```golang
func sortedListToBST(head *ListNode) *TreeNode {
	var arr []int
	for head != nil {
		arr = append(arr, head.Val)
		head = head.Next
	}
	return sortedArrayToBST(arr)
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	return &TreeNode{nums[len(nums)/2], sortedArrayToBST(nums[:len(nums)/2]), sortedArrayToBST(nums[len(nums)/2+1:])}
}
```

# 中序遍历
```golang
var head *ListNode

func sortedListToBST(h *ListNode) *TreeNode {
	var s int
	head = h
	for h != nil {
		s++
		h = h.Next
	}
	return convertListToBST(0, s-1)
}

func convertListToBST(l, r int) *TreeNode {
	if l > r {
		return nil
	}
	mid := (l + r) / 2
	left := convertListToBST(l, mid-1)
	node := &TreeNode{
		Val: head.Val,
	}
	node.Left = left
	head = head.Next
	node.Right = convertListToBST(mid+1, r)
	return node
}
```


[Go版本的一题多解 Github](https://github.com/temporaries/leetcode)
