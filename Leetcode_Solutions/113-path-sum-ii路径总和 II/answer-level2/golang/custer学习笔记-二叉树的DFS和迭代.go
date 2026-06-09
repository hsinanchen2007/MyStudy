### 解题思路 - 递归

之前的 路径和是否等于给定值[112. 路径总和，是存在路径等于给定值就返回true。](https://leetcode-cn.com/problems/path-sum/solution/custerxue-xi-bi-ji-er-cha-shu-de-di-gui-he-die-dai/)

这道题是返回所有满足条件的路径。因此两道题解法类似。

第一种直观的解法是递归遍历这棵二叉树，并且记录下在这个过程中节点上的值。

同时给定的和不断减去节点上的值。

最后在叶子节点上，如果节点值正好等于当前给定和，则找到一条满足条件的路径。

把这条路径加到结果列表即可。

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

// 辅助递归函数，输入二叉树和给定的整数和,elem用于存储路径上的值，result用于存储满足条件的路径
func path(root *TreeNode, sum int, elem []int, result *[][]int) {
   if root == nil { // 如果树为空
      return // 就直接返回
   }
   elem = append(elem, root.Val) // 把根节点的值加入到elem
   // 判断当前节点是否为叶子节点，并且节点上的值等于当前和
   if root.Left == nil && root.Right == nil && root.Val == sum { 
      tmp := make([]int, len(elem))
      copy(tmp, elem) // 如果是，就把存储了当前路径的elem加入到结果列表
      *result = append(*result, tmp) 
   } // 接下来递归处理左子树，sum要减去当前节点值
   // 即左子树上只要找到sum和为sum-root.Val的路径即可
   path(root.Left, sum-root.Val, elem, result)
   path(root.Right, sum-root.Val, elem, result) // 同样递归处理右子树
   // 退递归需要回溯到这一步结束前，需要将一开始键入到elem的那个元素移除
   elem = elem[:len(elem)-1] // 由于移除的是最后一个元素，所以时间复杂度是O(1)
}
func pathSum(root *TreeNode, sum int) [][]int {
   var result [][]int  // 首先定义结果列表result
   var elem []int // 和辅助列表elem
   path(root, sum, elem, &result) // 然后调用辅助递归函数,寻找路径
   return result // 最后返回结果即可
}
```

### 解题思路 - 迭代方法

使用递归的方式遍历二叉树，使用的是根左右的顺序，相当于对二叉树进行前序遍历，

与二叉树前序遍历一样，使用一个栈来模拟递归过程中入栈和出栈，从而实现迭代方法，

使用一个辅助栈，同样需要一个elem来记录遍历过程中访问到的节点值，

需要用一个result来记录找到的路径。另外使用一个curSum来记录累加和。

一开始沿着树的左侧分支不断入栈

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
func pathSum(root *TreeNode, sum int) [][]int {
   var result [][]int                     // 首先定义结果列表result
   var elem []int                         // 和辅助列表elem
   var stack []*TreeNode                  // 定义辅助栈
   visited := make(map[*TreeNode]bool, 0) // 定义集合set存储已经访问过的节点
   curSum := 0                            // 定义curSum记录累加和
   for root != nil || len(stack) > 0 {    // 当树不为空，或栈不为空时，循环执行以下操作
      for root != nil { // 先不断访问左侧分支，只要节点不为空
         elem = append(elem, root.Val) // 就把节点值加入到elem
         curSum += root.Val            // 并把节点值累加到curSum
         visited[root] = true          // 同时把访问过的节点加入到visited
         stack = append(stack, root)   // 并把它入栈
         root = root.Left              // 然后移动到它的左节点
      } // 节点为空以后，说明已经遍历完左侧分支
      // 接下来看栈顶元素的右节点
      n := stack[len(stack)-1]                // 先查看栈顶元素
      if n.Right == nil || visited[n.Right] { // 栈顶元素的右节点为空或已经访问过,无法再深入向下访问
         // 再出栈该节点之前，先判断当前节点是否为叶子节点，并且累加和已经等于sum
         if n.Left == nil && n.Right == nil && curSum == sum {
            tmp := make([]int, len(elem)) // 这里要重新 new 一个 List 的原因：
            copy(tmp, elem)               // 因为后面需要对原先的 List 做删除操作
            result = append(result, tmp)  // 如果是就把记录当前路径的elem加入到结果集合
         }
         stack = stack[:len(stack)-1] // 然后把栈顶节点出栈
         elem = elem[:len(elem)-1]    // 相应的把elem中最后的数字移除
         curSum -= n.Val              // 并且累加和要减去当前节点值
         root = nil                   // 最后把root置空，因为没有可以向下再深入访问的节点
      } else { // 如果不是这种情况，则说明节点n有右子树并且还未访问过
         root = n.Right // 于是更新root为n的右子树
      }
   }
   return result // 循环结束后返回结果列表即可
}


```