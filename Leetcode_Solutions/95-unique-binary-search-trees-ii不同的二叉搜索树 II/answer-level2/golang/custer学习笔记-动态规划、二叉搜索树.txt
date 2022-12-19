### 解题思路

[二叉搜索树的数量](https://leetcode-cn.com/problems/unique-binary-search-trees/solution/custerxue-xi-bi-ji-dong-tai-gui-hua-shu-by-custer-/)

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
// Time: O(4^n / n^(3/2)), Space: O(4^n / n^(3/2))
func generateTrees(n int) []*TreeNode {
  // 处理边界情况
  if n < 1 { // n小于1
    return nil // 返回空列表
  }
  // 调用辅助函数low等于1，high等于n
  return genTrees(1, n)
}

// 辅助函数用于拷贝这颗树
func cloneTree(root *TreeNode) *TreeNode {
  if root == nil { // 如果树为空
    return nil // 就直接返回
  }
  // 否则根节点的值取出，用它构造一个新的树节点
  newRoot := &TreeNode{Val: root.Val}
  // 然后递归的去拷贝左子树，并把它返回的结果作为新节点的左子树
  newRoot.Left = cloneTree(root.Left)
  // 同理递归拷贝右子树，并把结果作为新节点的右子树
  newRoot.Right = cloneTree(root.Right)
  return newRoot // 最后返回拷贝后的二叉树即可
}

// 函数f输入是大小整数low和high,
// 输出是用low到high这些整数可以生成的二叉搜索树列表
func genTrees(low, high int) []*TreeNode {
  // 先定义结果列表
  var result []*TreeNode
  // 递归终止条件
  if low > high {
    result = append(result, nil)
    return result // 返回只包含空树的列表即可
  }
  if low == high {
    // 返回一个只包含树节点的列表
    result = append(result, &TreeNode{Val: low})
    return result
  }
  // 接着处理其他情况,然后i从low遍历到high
  for i := low; i <= high; i++ {
    // 先递归调用自己，用i左边的数字生成左子树列表
    lefts := genTrees(low, i-1)
    // 同理用i右边的数字生成右子树列表
    rights := genTrees(i+1, high)
    // 接下来分别遍历左右子树列表，
    for _, left := range lefts {
      // 拿出一个左子树left和一颗右子树right
      for _, right := range rights {
        // 先用整数i构造一个树节点
        root := &TreeNode{Val: i}
        // 然后把左右子树拷贝一份后
        root.Left = cloneTree(left)
        // 挂到节点root的左右两边
        root.Right = cloneTree(right)
        // 最后把生成的二叉搜索树加入到结果列表
        result = append(result, root)
      }
    }
  }
  return result // 循环结束后返回结果列表即可
}
```