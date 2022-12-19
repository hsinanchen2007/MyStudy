### 思路
二叉树的前序遍历
### 完整代码
```
func isSameTree(p *TreeNode, q *TreeNode) bool {
    	stackp := make([]*TreeNode, 0, 0) // 使用队列模拟栈操作
	stackq := make([]*TreeNode, 0, 0)
	pNode := p
	qNode := q
	validStackLen := 0 //当前栈顶位置
	for pNode != nil || qNode != nil || validStackLen != 0 {
		// 有一个为nil  则不符合直接退出
		if pNode == nil && qNode != nil {
			return false
		}
		
		if pNode != nil && qNode == nil {
			return false
		}
		
		if pNode == nil && qNode == nil {
			pNode = stackp[validStackLen - 1].Right
			qNode = stackq[validStackLen - 1].Right
			validStackLen--
		}else {
			if pNode.Val != qNode.Val {
				return false
			}
			if len(stackq) > validStackLen {
				stackq[validStackLen] = qNode
				stackp[validStackLen] = pNode
			} else {
				stackq = append(stackq, qNode)
				stackp = append(stackp, pNode)
			}
			validStackLen++
			pNode = pNode.Left
			qNode = qNode.Left
		}
	}
	
	return true
}
```
执行结果
![image.png](https://pic.leetcode-cn.com/bb63c7f6cc489d9cefa572ba856d24ba04339ba6852321bc7ea5adc20a0bdb1b-image.png)
