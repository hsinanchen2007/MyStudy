### 解题思路
遇到树的题目一般用递归思路求解，先假设删除节点的函数是f(root,val)

显然如果树的根节点为空，if (root == nil ) => nil 那就直接返回空指针即可。

否则给你的数值和根节点之间数值的关系一种情况一种情况的分析。

给你的数值小于根节点的数值，说明要删除的节点在根节点的左子树上，

于是递归调用f去左子树上删除节点。

删除后返回的二叉搜索树也应该是当前根节点的左子树。

第二种情况是当给你的数值大于根节点的数值，说明要删除的节点在根节点的右子树上，

于是递归调用f去右子树上删除节点。

删除后返回的二叉搜索树仍然是当前根节点的右子树。

最后一种情况是给你的数值等于当前根节点的数值，说明找到了要删除的节点。

如果此时左右子树只有一个非空，那在删除掉当前根节点后，显然直接返回唯一的那个子树即可。

如果要删除节点的左右子树都不为空，这时我们要把左右子树合并起来，再返回。

那么怎么合并呢？ 如下图

![1.png](https://pic.leetcode-cn.com/4c43f3cc439b2b9b1dd34af180964e4347998c849885a8d04e5d2b082e05c558-1.png)


这种方法的每一轮操作都会进入树的下一层，所以时间复杂度是O(h)，h是树的高度，

空间复杂度和递归深度相关，最坏情况下递归深度就是树的高度，因此空间复杂度也是O(h)

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
// Time: O(h), Space: O(h) h是树的高度
func deleteNode(root *TreeNode, key int) *TreeNode {
   if root == nil { // 如果当前节点为空
      return nil // 就返回空指针
   }
   if key < root.Val { // 如果要删除的值小于根节点的值
      // 就递归去左子树上删除节点，并且返回的二叉树是当前根节点的左子树
      root.Left = deleteNode(root.Left, key)
   } else if key > root.Val { // 如果要删除的值大于根节点的值
      // 就递归去右子树上删除节点，并且返回的二叉树是当前根节点的右子树
      root.Right = deleteNode(root.Right, key)
   } else { // 如果不是以上两种情况，说明要删除的值等于当前根节点的值
      if root.Left == nil { // 先判断当前根节点是否只有一个子树
         return root.Right // 是的话就返回那个唯一子树即可
      } else if root.Right == nil {
         return root.Left
      }
      // 否则说明左右子树都不为空,去找左子树中的最大值对应的节点
      leftMax := root.Left       // 先移动到左子树
      for leftMax.Right != nil { // 如果左子树的右子树不为空
         leftMax = leftMax.Right // 就一直移动到它的右子树直到为空
      } // 找到左子树的最大值节点后，把当前根节点的右子树作为它的右子树
      leftMax.Right = root.Right
      root = root.Left // 然后把根节点移动到左子树
   }
   return root // 最后返回当前根节点即可
}
```