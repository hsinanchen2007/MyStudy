### 解题思路

还是老一套，直接套模板即可。这次终于没有丧心病狂的test case了。

### 代码

```scala
object Solution {
  def pathSum(root: TreeNode, sum: Int): List[List[Int]] = {
    def children(node: TreeNode): List[TreeNode] = {
      if (node.left != null && node.right != null) {
        List(node.left, node.right)
      } else if (node.left == null && node.right != null) {
        List(node.right)
      } else if (node.left != null && node.right == null) {
        List(node.left)
      } else {
        List()
      }
    }

    type Path = (Int, List[TreeNode])

    def genPath(path: Path): LazyList[Path] = {
      children(path._2.head)
        .map(node => (path._1 + node.value, node :: path._2))
        .to(LazyList)
    }

    def hasChildren(node: TreeNode): Boolean =
      node.left != null || node.right != null

    def legalPath(paths: LazyList[Path]): LazyList[Path] =
      paths.dropWhile(_._1 > sum)

    def from(paths: LazyList[Path]): LazyList[Path] =
      if (paths.isEmpty) LazyList.empty
      else {
        val more = for {
          path <- paths
          next <- genPath(path)
        } yield next
        paths ++ from(more)
      }

    lazy val initial = from(LazyList((root.value, List(root))))
    lazy val res: LazyList[List[Int]] = for {
      path <- initial
      if path._1 == sum && !hasChildren(path._2.head)
    } yield path._2.map(_.value).reverse

    if (root == null) List()
    else res.toList
  }
}
```