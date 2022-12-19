### 解题思路 - 递归方法
- 根节点无需和其他节点对比，然后看左右节点，如果左右节点值相等，
- 则递归的对比左节点的左子树和右节点的右子树，以及左节点的右子树和右节点的左子树。
- 递归的终止条件是左右两个节点都为空，则返回true，
- 如果一个为空，另一个非空，则返回false。

这个方法需要把二叉树上每个节点都访问一遍，因此时间复杂度是O(n),最坏的空间复杂度是O(n)。

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

// 辅助函数判断两个二叉树是否对称
func isSymmetricHelp(s, t *TreeNode) bool {
   if s != nil && t != nil { // 如果两个树都不为空
      // 则由根节点上的值是否相等，以及左节点的左子树和右节点的右子树是否对称，以及左节点的右子树和右节点的左子树是否对称
      return s.Val == t.Val && isSymmetricHelp(s.Left, t.Right) && isSymmetricHelp(s.Right, t.Left) // 这三个条件共同决定
   } else { // 否者
      return s == nil && t == nil // 这两个树是否对称由他们是否都为空决定
   }

}

// Time: O(n), Space: O(n)
func isSymmetric(root *TreeNode) bool {
   if root == nil { // 如果树为空
      return true
   }
   // 否者返回根节点的左右子树对称性
   return isSymmetricHelp(root.Left, root.Right)
}
```

### 解题思路 - 迭代方法
迭代方法，我们把递归的方法翻译成迭代的版本，
对于这个题目，在递归的过程中，对比的节点数量是在不断增加，
因此需要一个辅助的数据结构来保存，使用栈或者队列都可以，

- 这里使用栈，当两个栈顶的两个值对比相等后，
- 依次把左节点的左子树和右节点的右子树，左节点的右子树和右节点的左子树，这四个节点依次入栈。

时间复杂度是O(n),n是总的节点数量，额外需要规模为n的辅助栈，空间复杂度是O(n)。

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

// Time: O(n), Space: O(n)
func isSymmetric(root *TreeNode) bool {
   if root == nil { // 如果树为空
      return true
   }
   var stack []*TreeNode             // 定义辅助栈
   stack = append(stack, root.Left)  // 并把根节点的左右子树入栈
   stack = append(stack, root.Right) // 并把根节点的左右子树入栈

   for len(stack) > 0 { // 当栈不为空时，不断执行以下操作
      s := stack[len(stack)-1] // 把栈顶的两个元素出栈
      stack = stack[:len(stack)-1]
      t := stack[len(stack)-1] // 把栈顶的两个元素出栈
      stack = stack[:len(stack)-1]
      if s == nil && t == nil { // 当它们都为空时，表示当前的两个子树对称
         continue // 继续对比栈内其他的子树
      }
      if s == nil || t == nil { // 如果一个子树为空，另一个不为空
         return false // 则肯定不对称，直接返回false
      }
      // 如果没有在前面两个条件提前返回，说明两个子树都非空
      if s.Val != t.Val { // 则判断节点的值
         return false // 如果不相等，则返回false
      }

      stack = append(stack, s.Left)  // 如果相等，则把左节点的左子树，
      stack = append(stack, t.Right) // 右节点的右子树，
      stack = append(stack, s.Right) // 左节点的右子树和
      stack = append(stack, t.Left)  // 右节点的左子树依次入栈,开始新一轮的对比
   } // 如果循环结束还没有提前返回，说明这个树是对称的
   return true // 直接返回true
}

```