```scala
object Solution {
  def canFinish(numCourses: Int, prerequisites: Array[Array[Int]]): Boolean = {
    val graph: Array[Array[Int]] = Array.fill(numCourses, 0)(0)
    val flag = Array.fill(numCourses)(0)
    prerequisites.foreach(i => graph(i(1)) :+= i(0))
    (0 until numCourses).foreach(i => if (!dfs(graph, flag, i)) return false)
    true
  }

  def dfs(graph: Array[Array[Int]], flag: Array[Int], idx: Int): Boolean = flag(idx) match {
    case -1 => false
    case 1 => true
    case _ =>
      flag(idx) = -1
      graph(idx).foreach(i => if (!dfs(graph, flag, i)) return false)
      flag(idx) = 1
      true
  }
}

```
