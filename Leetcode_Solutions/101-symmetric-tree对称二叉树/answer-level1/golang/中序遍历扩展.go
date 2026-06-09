golang 实现，时间复杂度空间复杂度均为 O(n)
执行用时 4ms, 击败70 % 内存消耗 3MB, 击败 16%
实现思路是在 对中序遍历一个二叉树进行扩展，正常的中序遍历时会有一个指针一路向左遍历，这道题中添加另一个指针做相反的操作，并比较两个指针的值及两个栈的状态。
```
type Stack struct {
	container []interface{}
}

func (this *Stack) Pop() (interface{}, bool){
	if len(this.container) == 0 {
		return "", false
	}
	rs := this.container[len(this.container) - 1]
	this.container = this.container[:len(this.container) - 1]
	return rs, true
}

func (this *Stack) Push(s interface{}) {
	this.container = append(this.container, s)
}

func (this *Stack) Len() int{
	return len(this.container)
}

func isSymmetric(root *TreeNode) bool {
	s1 := Stack{container: []interface{}{}}
	s2 := Stack{container: []interface{}{}}
	cur1 := root
	cur2 := root
	
	for (s1.Len() > 0 && s2.Len() > 0) || (cur1 != nil && cur2 != nil) {
		for cur1 != nil {
			s1.Push(cur1)
			cur1 = cur1.Left
		}
		for cur2 != nil {
			s2.Push(cur2)
			cur2 = cur2.Right
		}
		if s1.Len() != s2.Len() { return false }
		top1, _ := s1.Pop()
		top2, _ := s2.Pop()
		cur1 = top1.(*TreeNode)
		cur2 = top2.(*TreeNode)
		if cur1.Val != cur2.Val { return false }
		cur1 = cur1.Right
		cur2 = cur2.Left
	}
	if s1.Len() != s2.Len() {return false}
	if cur1 != cur2 {return false}
	return true
}
```
