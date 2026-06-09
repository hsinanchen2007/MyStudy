### 解题思路
1.将一个点作为标准点，后边的每个点和标准店对比，分别计算斜率。**值得注意的是，当两个点的横坐标相等时，我们把斜率赋值为Double.MAX_VALUE,就避免了斜率计算时分母为0的情形**；
2.如果每个点的斜率相等，那么这些点在一条直线上。

### 代码
```java []
 public static boolean checkStraightLine(int[][] coordinates) {
        int size = coordinates.length;
        if(size == 2) return true;
        int x0 = coordinates[0][0],y0 = coordinates[0][1];
        double[] flag = new double[size - 1];
        for (int i = 1; i < size ; i++) {
            int[] arr_i = coordinates[i];
            if(arr_i[0] - x0 == 0) flag[i-1] = Double.MAX_VALUE;
            else  flag[i-1] =(double)(arr_i[1] - y0)/(arr_i[0] - x0);
        }

        for (int i = 1; i < flag.length ; i++) {
            if(flag[i] != flag[0]) return false;
        }

        return true;
    }
```

```scala []
object Solution {
    def checkStraightLine(coordinates: Array[Array[Int]]): Boolean = {
    if (coordinates.length == 2) true
    else {
      val flag = new Array[Double](coordinates.length - 1)
      for (a <- 1 until coordinates.length) {
        val arr: Array[Int] = coordinates(a)
        if (arr(0) - coordinates(0)(0) == 0) {
          flag(a - 1) = Int.MaxValue
        } else {
          flag(a - 1) = (arr(1).toDouble - coordinates(0)(1).toDouble) / (arr(0).toDouble - coordinates(0)(0).toDouble)
        }
      }

      if(flag.toSet.seq.size == 1) true
      else false
    }
  }
}
```
