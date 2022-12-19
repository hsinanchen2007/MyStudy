object LeetCode1266 extends App {

  println(minTimeToVisitAllPoints(Array(Array(1, 1), Array(3, 4), Array(-1, 0))))

  //[[1,1],[3,4],[-1,0]],先对所有点提取同轴坐标，两两计算同轴再求abs和max、sum
  def minTimeToVisitAllPoints(points: Array[Array[Int]]): Int = {
    points.zipWithIndex.collect {
      case (num, index) if index < points.length - 1 =>
        Array(Math.max(Math.abs(num(0) - points(index + 1)(0)), Math.abs(num(1) - points(index + 1)(1))))
    }.flatten.sum
  }
}