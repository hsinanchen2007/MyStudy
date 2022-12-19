为啥没人用scala，写个scala，虽然通过率不高，但是给个思路

```
package tree.easy

import common.TreeNode

object DiameterOfBinaryTreeScala {

  private var maxpath = 1

  /**
    * 执行用时 : 608 ms , 在所有 Scala 提交中击败了 16.67% 的用户
    * 内存消耗 : 53.5 MB , 在所有 Scala 提交中击败了 100.00% 的用户
    *xiaof
    * @param root
    * @return
    */
  def solution(root: TreeNode): Int = {
    if (root == null) return 0
    maxpath = 1
    deepcount(root)
    maxpath - 1
  }


  private def deepcount(node: TreeNode): Int = {
    if (node == null) return 0

    //求左右深度
    val lpath = deepcount(node.left)
    val rpath = deepcount(node.right)
    maxpath = Math.max(maxpath, lpath + rpath + 1);
    Math.max(lpath, rpath) + 1
  }

  def main(args: Array[String]): Unit = {
    var n1 = new TreeNode(1)
    n1 = TreeNode.makeTree(Array[Integer](1, 2, 3, 4, 5))
    n1 = TreeNode.makeTree(Array[Integer](1))

    val r = DiameterOfBinaryTreeScala.solution(n1)

    System.out.println(r)
  }

}

```
