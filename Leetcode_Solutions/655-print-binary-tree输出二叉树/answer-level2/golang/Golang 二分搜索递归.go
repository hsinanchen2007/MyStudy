### 解题思路

十分感谢 💕💕💕💖💖 [花花酱的视频解说](https://zxi.mytechroad.com/blog/tree/leetcode-655-print-binary-tree/)


这道题的难点在于构建输出二维数组。数组构建之后，就可以通过类似`二分搜索`来递归填充这个输出数组。

首先需要通过递归获得这个数的高度`h`， 获得这个高度之后，就能通过树在饱满的情况下最底层叶节点的个数`2^n - 1`。

这个 `2^n-1` 可以通过位运算获得 `(1<<n) -1`。

接下来就可以通过类似二分搜索来填充这个数组，从顶端节点开始，将一个指向二维数组的指针、当前的高度、可用范围传入递归。


### 例子
```
     1
    / \
   2   3
    \
     4
```

算出高度是3， 宽度是 7， 构建 3x7的二维数组。

* 1 `fill(root, ans, 0, 0, 6)`, 得到`mid=3`。 
* 2 `fill(2, ans, 2, 0, 2)` 和 `fill(3, ans, 2, 4, 6)`  



### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import (
	"strconv"
)


// getHeight 返回树的高度。
//
// 递归计算树的高度是典型的递归运算。
func getHeight(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return max(getHeight(root.Left), getHeight(root.Right)) + 1
}

// max 返回最大值。
//
// 一个辅助函数。
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func printTree(root *TreeNode) [][]string {
	// 计算输出数组的规模
	h := getHeight(root)
	// 宽度（最底层的宽度）， 2^n - 1
	w := (1 << h) - 1 
	// 构造答案二维数组（slice）
	ans := make([][]string, h)
	for i := range ans {
		ans[i] = make([]string, w)
	}
	fill(root, &ans, 0, 0, w-1)
	return ans
}


// fill 递归的填充。
//
// 对当前传入的数，如果是空树，则返回。
// 我们获得当前可填充范围，计算出中位数mid，在二维数组的[h][mid]填充节点值，
// 然后递归对左节点，右节点调用fill方法。
func fill(root *TreeNode, ans *[][]string, h, l, r int) {
	if root == nil {
		return
	}
	mid := (l+r) / 2
	(*ans)[h][mid] = strconv.Itoa(root.Val)
	fill(root.Left, ans, h+1, l, mid-1)
	fill(root.Right, ans, h+1, mid+1, r)
}
```