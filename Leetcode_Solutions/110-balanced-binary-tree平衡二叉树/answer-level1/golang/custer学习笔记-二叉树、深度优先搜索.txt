### 解题思路 - 递归
直观的使用递归求解

对于根节点只要计算它的左右子树高度差小于等于1，并且它的左右子树也是一颗平衡二叉树，那么这棵二叉树就是平衡的。

当这棵树是一棵满二叉树时，算法达到最坏时间复杂度，假设树的一共有n个节点，对于根节点计算树的高度，要访问所有的节点，因此时间复杂度是O(n)，对于子节点，它们访问树的高度，需要访问一半的节点，因此对于两个子节点，它们的时间复杂度都是O(n/2),因此这一层加起来也是O(n),同理下一层也是O(n),树的层数是logn，因此总的时间复杂度是O(nlogn),

最坏的空间复杂度是O(n),比如当树只有最左或最右一个分支时，递归调用达到最大深度n。

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
// 辅助函数，求树的高度，输入是一棵二叉树，输出是树的高度
func getHeight(root *TreeNode) int {
   if root == nil { // 如果树为空
      return 0 // 则返回高度为0
   }
   left := getHeight(root.Left)   // 否则分别计算出左右子树的高度
   right := getHeight(root.Right) // 否则分别计算出左右子树的高度
   if right < left {              // 然后返回他们中较大的值，并加一即可
      return left + 1
   }
   return right + 1
}

// 自顶向下的方法  Time: O(nlog(n)), Space: O(n)
func isBalanced(root *TreeNode) bool {
   if root == nil { // 如果树为空
      return true // 则返回true
   } // 否者这棵树是平衡二叉树需要满足
   // 左右子树的高度差小于等于1，并且左右子树仍然是一棵平衡二叉树
   return math.Abs(float64(getHeight(root.Left))-float64(getHeight(root.Right))) <= 1 &&
      isBalanced(root.Left) && isBalanced(root.Right)
}
```

### 解题思路
这个算法时间复杂度之所以需要用到O(nlogn),是因为从树的根节点向下遍历所有树的节点，求出它们的子树高度再进行对比，求子树高度过程中，节点被重复访问，如果我们在求子树高度时，同时进行左右子树的对比，这样一来，子树的对比是从下往上的.

因此，最坏的情况下，所有的节点只需要被访问一次，时间复杂度降为O(n),最坏的空间复杂度还是O(n)

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
// 辅助函数，计算树高度的同时检查子树是否平衡
// 输入是一棵二叉树，输出有两层含义，非负数表示树的高度，-1表示这棵树不平衡
func getHeightAndCheck(root *TreeNode) int {
   if root == nil { // 如果树为空
      return 0 // 则返回高度为0
   }
   left := getHeightAndCheck(root.Left) // 否则先计算左子树的高度
   if left == -1 {                      // 如果等于-1，说明不是一棵平衡二叉树
      return -1 // 直接返回-1结束递归
   }
   right := getHeightAndCheck(root.Right) // 否则接着计算右子树的高度
   if right == -1 {                       // 如果等于-1，说明不是一棵平衡二叉树
      return -1 // 直接返回-1结束递归
   }

   // 如果没有提前返回，说明左右子树返回一个正常的高度值，
   if math.Abs(float64(left-right)) > 1 { // 检查他们的差如果大于1
      return -1 // 说明不是一棵平衡二叉树,返回-1
   }
   if left > right { // 否则返回左右子树中较大的高度值并+1
      return left + 1
   }
   return right + 1
} // 对比纯粹求树的高度的辅助函数，这里加了求树是否平衡的判断，如果已经不平衡直接返回-1

// 自底向上的方法  Time: O(n), Space: O(n)
func isBalanced(root *TreeNode) bool {
   return getHeightAndCheck(root) != -1
}
```