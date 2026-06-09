### 还有三个用例没有通过，尽力了

“不是国军无能，是共军太狡猾”

代码有很多疏漏的地方，但是思路应该没错。利用惰性计算边穷举边筛选，但是最后几个用例实在是变态……

![图片.png](https://pic.leetcode-cn.com/bca38026f79e01bac554ba7b46473de63d3bb033d38ed4a2fe13ea8f41b603c3-%E5%9B%BE%E7%89%87.png)

### 代码

```scala
trait MatrixSolver {

  val problem: Array[Array[Char]]

  val goal: String

  type Dot = (Int, Int)

  type Path = (Dot, String)

  def genStart(char: Char): IndexedSeq[Dot] = for {
    i <- problem.indices
    j <- problem(0).indices
    if problem(i)(j) == char
  } yield (i, j)


  def genNext(path: Path, chars: List[Char], history: List[Dot]): LazyList[(Path, List[Char], List[Dot])] =
    chars match {
      case ::(head, next) => {
        neighbors(path._1).filter(dot => legalDots(dot, head)).foldRight(List[(Path, List[Char], List[Dot])]()) {
          (p, acc) =>
            if (history.contains(p)) acc
            else (p -> (path._2 + problem(p._1)(p._2)), next, p :: history) :: acc
        }.to(LazyList)
      }
      case Nil => LazyList.empty[(Path, List[Char], List[Dot])]
    }



  def legalDots(dot: Dot, next: Char): Boolean =
    if (dot._1 < 0 || dot._2 < 0 || dot._1 >= problem.length || dot._2 >= problem(0).length)
      false
    else if (problem(dot._1)(dot._2) != next) false
    else true

  def neighbors(dot: Dot): List[Dot] =
    List((dot._1 - 1, dot._2), (dot._1 + 1, dot._2), (dot._1, dot._2 + 1), (dot._1, dot._2 - 1))

  def done(path: Path): Boolean =
    path._2.length == goal.length

  def from(initial: LazyList[(Path, List[Char], List[Dot])]): LazyList[(Path, List[Char], List[Dot])] =
    if (initial.isEmpty) LazyList.empty
    else {
      val more = for {
        path <- initial
        next <- genNext(path._1, path._2, path._3)
      } yield next
      initial ++ from(more)
    }

  lazy val start = genStart(goal.charAt(0)).map(s =>
    ((s, goal.charAt(0).toString), goal.toCharArray.toList.drop(1), List(s))).to(LazyList)

  lazy val pathFromStart = from(start)

  lazy val solution = for {
    i <- pathFromStart
    if done(i._1)
  } yield i

  lazy val res = solution.exists(_._1._2 == goal)

  def printPossiblePath(): Unit =
    solution foreach { a =>
      println(a._1._2 + "  path: " + a._2.reverse.mkString(" -> ") + " goal: " + a._1._1)
    }

  def printStart(): Unit =
    start foreach { a =>
      println(a._1._2 + "  path: " + a._2.reverse.mkString(" -> ") + " goal: " + a._1._1)
    }
}

object Solution {
    def exist(board: Array[Array[Char]], word: String): Boolean = {
        val game = new MatrixSolver {
            val problem = board
            val goal = word
        }
        game.res
    }
}
```
