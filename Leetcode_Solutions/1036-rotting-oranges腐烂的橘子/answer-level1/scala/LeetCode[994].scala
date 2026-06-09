```
object Solution {
  def orangesRotting(grid: Array[Array[Int]]): Int = {
    import scala.collection.mutable.Queue
    var num = 0
    val mymap = scala.collection.mutable.Map[(Int, Int), Int]()
    val myqueue = new Queue[(Int, Int)]()
    val rows = grid.length
    val cols = grid(0).length

    val seeds = for (i <- 0 to rows - 1; j <- 0 to cols - 1 if grid(i)(j) == 2) yield (i, j)

    for (item <- seeds) {
      myqueue.enqueue(item)
    }
    while (myqueue.nonEmpty) {
      num += 1
      println("=================")
      val points = myqueue.dequeueAll(_ => true)
      for (point <- points) {
        if (mymap.contains(point)) {
          println("map contains " + point)
        } else {
          println("process point" + point)
          val x = point._1
          val y = point._2

          grid(x)(y) = 2
          mymap(point) = 1

          if (x - 1 >= 0 && grid(x - 1)(y) == 1
            && !points.contains((x - 1, y))
            && !mymap.contains((x - 1, y))) {
            println("add", (x - 1, y))
            myqueue.enqueue((x - 1, y))
          }
          if (y - 1 >= 0 && grid(x)(y - 1) == 1
            && !points.contains((x, y - 1))
            && !mymap.contains((x, y - 1))) {
            println("add", (x, y - 1))
            myqueue.enqueue((x, y - 1))
          }
          if (x + 1 <= rows - 1 && grid(x + 1)(y) == 1
            && !points.contains((x + 1, y))
            && !mymap.contains((x + 1, y))) {
            println("add", (x + 1, y))
            myqueue.enqueue((x + 1, y))
          }
          if (y + 1 <= cols - 1 && grid(x)(y + 1) == 1
            && !points.contains((x, y + 1))
            && !mymap.contains((x, y + 1))) {
            println("add", (x, y + 1))
            myqueue.enqueue((x, y + 1))
          }
        }
      }
    }
    if (grid.forall(_.forall(_ != 1))) {
      if (num > 0) return num - 1
      else return 0
    }
    else -1
  }

  def main(args: Array[String]): Unit = {
    val arr = Array(Array(2, 1, 0), Array(1, 1, 0), Array(0, 1, 1))
    orangesRotting(arr)
  }
}
```
