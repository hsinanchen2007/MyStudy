### 解题思路

利用题目给定的条件进行建模，然后使用`LazyList`生成一个无限流（注意`from`函数）。建模完成后根据题目的条件筛选出合格的答案即可。

这种方法也可以用来解决一些动态规划和DFS的问题。

当然也可以用递归。

### 代码

```scala [] 
object Solution {
  def findContinuousSequence(target: Int): Array[Array[Int]] = {
    val game = new ContinuousSequence {
      val goal = target
    }
    game.solver
  }

  trait ContinuousSequence {
    val goal: Int
    type Path = (Int, List[Int])

    def genNext(path: Path): LazyList[Path] =
      List((path._1 + path._2.head + 1, (path._2.head + 1) :: path._2)).to(LazyList)

    def legalPath(paths: LazyList[Path]): LazyList[Path] =
      paths.filter(isLegal)

    def isLegal(path: Path): Boolean =
      if (path._1 > goal) false
      else true

    def done(path: Path): Boolean =
      path._1 == goal

    def from(paths: LazyList[Path]): LazyList[Path] =
      if (paths.isEmpty) LazyList.empty
      else {
        val more = for {
          path <- paths
          next <- legalPath(genNext(path))
        } yield next
        paths ++ from(more)
      }

    lazy val solver = (for {
      start <- 1 until goal
      path <- from(LazyList((start, List(start))))
      if done(path)
    } yield path._2.reverse.toArray).toArray
  }
}
```
```scala []
// 递归解法
object Solution {
  def findContinuousSequence(target: Int): Array[Array[Int]] = {
    @scala.annotation.tailrec
    def dfs(sum: Int, history: List[Int]): List[Int] = {
      if (sum == target) history
      else if (sum + history.head + 1 > target) Nil
      else {
        dfs(sum + history.head + 1, (history.head + 1) :: history)
      }
    }
    val res = for {
      i <- 1 until target
    } yield dfs(i, List(i))
    res.filter(_.nonEmpty).map(_.reverse.toArray).toArray
  }
}
```