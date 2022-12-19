```
object Solution {
  def updateDirection(direction: Int, command: Int): Int = {
    if (command == -1) (direction + 1) % 4 else (direction + 3) % 4
  }
  def robotSim(commands: Array[Int], obstacles: Array[Array[Int]]): Int = {
    var maxDistance = 0
    val set: Set[String] = obstacles.map(x => x(0).toString + ":" + x(1).toString).toSet
    val dir = Map[Int, (Int, Int)](
      0 -> (0, 1),
      1 -> (1, 0),
      2 -> (0, -1),
      3 -> (-1, 0)
    )
    val initPosition = (0, 0)
    val initDir = 0

    def updatePosition(p: (Int, Int), d: Int, c: Int): (Int, Int) = {
      val (dx, dy) = dir(d)
      var x = p._1
      var y = p._2
      import util.control.Breaks._
      breakable {
        for (i <- 0 until c) {
          val newX = x + dx
          val newY = y + dy
          if (set.contains(newX.toString + ":" + newY.toString)) {
            break
          } else {
            x = newX
            y = newY
          }
        }
      }
      (x, y)
    }

    val ret = commands.foldLeft(initPosition, initDir)((z: ((Int, Int), Int), c: Int) => {
      c match {
        case int: Int if List(-1, -2) contains int => (z._1, updateDirection(z._2, c))
        case _ => {
          val position = updatePosition(z._1, z._2, c)
          val tmp = position._1 * position._1 + position._2 * position._2
          maxDistance = math.max(tmp, maxDistance)
          (position, z._2)
        }
      }
    })
    maxDistance
  }
}
```

注意最后是求取最大的距离， 而非最后位置的距离。
