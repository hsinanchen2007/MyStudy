// 感谢素未谋面, ❤❤💖💖✔✔，[我的老师**花花酱**视频讲解](http://zxi.mytechroad.com/blog/tree/leetcode-113-path-sum-ii/)。

// ### 递归例子

// 给这棵树，要找出的 `sum=22`
// ```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
// ```

// 递归的过程：

// * `fsp(5, 22, [], [][])`
   
//    * `fsp(4, 17, [5], [][])`
      
//       * `fsp(11, 13, [5,4], [][])`
//         * `fsp(7, 2, [5,4,11], [][])`, return
//         * `fsp(2, 2, [5,4,11], [][])`, `ans=[[5,4,11]]`, return
        
//       * `fsp(nil, 13, [5,4],[][])`, return

   
//    . `fsp(8, 17, [5], [][])`, 略

// 每个递归退出，都会pop出cur。

// ### Golang 需要注意的地方

// * Go 里面的 slice的clone不是简单的赋值，因为slice是一个很小的数据结构，几个slice有可能公用同一个底层的数组。因此，在将临时结果添加到最终结果的时候，由于临时结果是一个不断被重复利用的slice，我们需要将它的一个copy或者clone保存在最终结果内。这样才能保证在下次递归的时候操作临时结果`cur`不会影响到已经保存好的结果。

      
// ```
// 复制slice的范例
copy := make([]int, 0)
copy = append(copy, source...)
// ```

// * Go 没有类似C的指针运算，如果使用指针稍微麻烦了一点，但是空间消耗被大大减少了。


// ### 代码

// ```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, sum int) [][]int {
	// The answer to be returned.
	ans := make([][]int, 0)
	// The current answer for one path.
	// This slice store the temporary list of values
	// that sum up to be the sum we want.
	// It works like an accumulator.
	cur := make([]int, 0)
	findPathSum(root, sum, &cur, &ans)
	return ans
}

func findPathSum(root *TreeNode, sum int, cur *[]int, ans *[][]int) {
	// Empty Node do nothing.
	if root == nil {
		return
	}

	// Leave Node
	if root.Left == nil && root.Right == nil {
		// We find the answer
		if root.Val == sum {
			// First append the value into the current slice.
			*cur = append(*cur, root.Val)
			// Append the final accumulator's values into answer.
			// Watch out this time we need append a *Copy* of current slice
			copy := make([]int, 0)
			copy = append(copy, (*cur)...)
			*ans = append(*ans, copy)
			// Pop this value out
			*cur = (*cur)[:len(*cur)-1]
		}
		return
	}

	// Middle stage
	*cur = append(*cur, root.Val)
	newSum := sum - root.Val
	findPathSum(root.Left, newSum, cur, ans)
	findPathSum(root.Right, newSum, cur, ans)
	*cur = (*cur)[:len(*cur)-1]
}
// ```