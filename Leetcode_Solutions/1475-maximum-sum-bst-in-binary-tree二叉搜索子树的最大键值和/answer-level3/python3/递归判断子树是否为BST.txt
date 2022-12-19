本题中的树为**二叉树**，而题目中要求的是**二叉搜索树BST**的最大和，那么问题的关键就变成了如何判断子树为二叉搜索树。

从二叉搜索树的定义考虑：
- 任意节点的左子树中的键值都 **小于** 此节点的键值。
- 任意节点的右子树中的键值都 **大于** 此节点的键值。
- 任意节点的左子树和右子树都是二叉搜索树。

前两点要求我们在递归过程中**找到子树中的最大值与最小值**，最后一点要求**子树为二叉搜索树**。对于一颗二叉搜索树容易知道其最大值对应右子树中的最大值，最小值对应左子树中的最小值，因此整个递归式就比较清晰了。

Python代码如下
```python3
class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        self.result = float('-inf')
        def isBST(node, left=True):
            if node:
                lt, lSum, lMax, lMin = isBST(node.left, True)
                rt, rSum, rMax, rMin = isBST(node.right, False)

                if lt and rt and node.val > lMax and node.val < rMin:
                    curSum = lSum + rSum + node.val
                    self.result = max(self.result, curSum)
                    # 以下为左右子树为空的情况，需要取自身节点值返回
                    if rMax == 1 << 31:
                        rMax = node.val
                    if lMin == float('-inf'):
                        lMin = node.val
                    return True, curSum, rMax, lMin
                
                return False, 0,0,0
            
            if left:
                return True , 0, float('-inf'), float('-inf')
            else:
                return True, 0, 1 << 31, 1 << 31

        isBST(root)
        return self.result if self.result >= 0 else 0
```

Go代码如下：
```go
 func maxSumBST(root *TreeNode) int {
	const MaxUint = ^uint(0) 
	const MinUint = 0 
	const MaxInt = int(MaxUint >> 1) 
	const MinInt = -MaxInt - 1
	maximum := MinInt

	var isBST func(*TreeNode, bool) (bool, int, int, int) 
	isBST = func(node *TreeNode, left bool) (bool, int, int, int) {
		if node != nil {
			lt, lSum, lMax, lMin := isBST(node.Left, true)
			rt, rSum, rMax, rMin := isBST(node.Right, false)

			if lt && rt && node.Val > lMax && node.Val < rMin {
				curSum := lSum + rSum + node.Val
				maximum = max(maximum, curSum)
				if lMin == MinInt {
					lMin = node.Val
				}
				if rMax == MaxInt {
					rMax = node.Val
				}
				return true, curSum, rMax, lMin
			}
			return false, 0, 0, 0
		}
		if left {
			return true, 0, MinInt, MinInt
		} else {
			return true, 0, MaxInt, MaxInt
		}
	}
	isBST(root, true)
	if maximum < 0 {
		maximum = 0
	}
	return maximum
}
```

