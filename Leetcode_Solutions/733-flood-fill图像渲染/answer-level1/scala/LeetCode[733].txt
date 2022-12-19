```
object Solution {
  case class Point(r: Int, c: Int)
  def dfs(image: Array[Array[Int]],
          sr: Int, sc: Int,
          newColor: Int,
          mymap: scala.collection.mutable.Map[Point, Int],
          oldColor: Int): Unit = {
    if (mymap.contains(Point(sr, sc)) || image(sr)(sc) != oldColor) return
    else {
      mymap(Point(sr, sc)) = 1
      image(sr)(sc) = newColor
    }
    println("sr:", sr, "sc:", sc)
    if (sr - 1 >= 0 && !mymap.contains(Point(sr - 1, sc))) dfs(image, sr - 1, sc, newColor, mymap, oldColor)
    if (sc - 1 >= 0 && !mymap.contains(Point(sr, sc - 1))) dfs(image, sr, sc - 1, newColor, mymap, oldColor)
    if (sr + 1 <= image.length - 1 && !mymap.contains(Point(sr + 1, sc))) dfs(image, sr + 1, sc, newColor, mymap, oldColor)
    if (sc + 1 <= image(0).length - 1 && !mymap.contains(Point(sr, sc + 1))) dfs(image, sr, sc + 1, newColor, mymap, oldColor)
  }

  def floodFill(image: Array[Array[Int]], sr: Int, sc: Int, newColor: Int): Array[Array[Int]] = {
    val mymap = scala.collection.mutable.Map[Point, Int]()
    if (newColor == image(sr)(sc)) return image
    dfs(image, sr, sc, newColor, mymap, image(sr)(sc))
    image
  }
}

```
