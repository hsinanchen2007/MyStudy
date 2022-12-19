

### 思路

使用双指针方式，left、right分别指向生成数字的前后端。


输入为3时，递归示意图，

![image.png](https://pic.leetcode-cn.com/831b9f9a00fd36bb770549a34e693639be9021529b7c22855c361aa597d64b2e-image.png)



```运行结果
执行用时 : 4 ms , 在所有 golang 提交中击败了 96.59% 的用户 

内存消耗 : 4.3 MB , 在所有 golang 提交中击败了 100.00% 的用户
```


```
func generateTrees(n int) []*TreeNode {

	if n == 0 {
		return nil
	}

	return doGenerateTrees(1, n)
}

// 递归生成从[left, right]区间范围内的树
func doGenerateTrees(left, right int) []*TreeNode {

	if left > right {
        return []*TreeNode{nil}
	}

	if left == right {
		return []*TreeNode{&TreeNode{Val: left}}
	}

	trees := make([]*TreeNode, 0, right-left+1)
	for i := left; i <= right; i++ {
		// 以i为根节点，生成左右子节点

		leftTrees := doGenerateTrees(left, i-1)
		rightTrees := doGenerateTrees(i+1, right)

		// 拼接所有的树
		for m := 0; m < len(leftTrees); m++ {
			for n := 0; n < len(rightTrees); n++ {
				tree := &TreeNode{Val: i}

				tree.Left = leftTrees[m]
				tree.Right = rightTrees[n]
				trees = append(trees, tree)
			}
		}
	}

	return trees
}
```
