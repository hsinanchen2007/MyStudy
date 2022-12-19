### 解题思路
先层序遍历二叉树，再把结果数据对调一下即可。

借助辅助队列，达到层序遍历，先把根节点1入队，

当队列不为空时，先取出当前队列的元素个数，以此作为限定，

确保访问中，只访问当前层级的节点，不访问在这个过程中子树入队的节点。

对这个例子，当前队列大小为1，因此只访问队列中的一个节点。

同时把它的非空子树入队，根节点1的左右子树都不为空，因此入队2， 4。

此时队列不为空，继续重复同样的操作，队列大小为2。

说明这一层有2个节点，依次出队，先把2出队，它的左右子树都为空，不需要入队。

再把4出队，它的左右子树都不为空，所以把8和16入队。

由于这一轮只有2个节点，所以8和16在下一轮进行访问。

当前队列不为空，继续重复同样的操作。

至此队列为空，得到了层序遍历的结果，[[1],[2,4],[8,16]],

最后将这个数组，以中心轴对称的元素，两两交换，就得到这棵树逆层序的遍历结果。

使用这种方法，每个树的节点都要被访问两次，因此时间复杂度为O(n)，n为树的节点数量。

辅助队列的规模和n线性相关，因此空间复杂度也是O(n)。
![2.png](https://pic.leetcode-cn.com/d92189580b717ae76ee399fbe99291e98311e1a61e8f43ee8514fb84abdbc53a-2.png)


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
func levelOrderBottom(root *TreeNode) [][]int {
   if root == nil { // 如果树为空
      return [][]int{} // 返回空的list
   }
   var result [][]int  // 定义要返回的结果
   var q []*TreeNode   // 定义辅助队列
   q = append(q, root) // 同时把根节点入队

   for len(q) > 0 { // 当队列不为空时，循环以下操作
      var elem []int              // 定义list保存这一层级访问到的元素
      size := len(q)              // 然后把当前队列大小取出,表示的是当前层级中节点的个数
      for i := 0; i < size; i++ { // 使用for循环执行以下操作
         s := q[0] // 把队首的节点出队
         q = q[1:]
         elem = append(elem, s.Val) // 把队首的节点数值加入list
         if s.Left != nil {         // 如果左子树不为空
            q = append(q, s.Left) // 则把左子树入队
         }
         if s.Right != nil { // 如果右子树不为空
            q = append(q, s.Right) // 则把右子树入队
         }
      }
      // for循环结束后，说明这一层级节点已经访问完
      // 把保存访问结果的list加入到result
      result = append(result, elem)
   }
   // 循环结束后，result保存的是二叉树层序遍历的结果
   // 使用for循环，把沿中心轴对称的元素对调，以此来反转数组
   for i := 0; i < len(result)/2; i++ {
      j := len(result) - i - 1
      result[i], result[j] = result[j], result[i]
   }
   return result // 最后返回result即可
}

```