直接上代码，需要导入Breaks类
import scala.util.control.Breaks
```
def minDeletionSize(A: Array[String]): Int = {
    var result = 0
    val loop=new Breaks

      for (i <- 0 to A(0).size - 1) {
        loop.breakable {
        for (j <- 0 to A.size - 2) {
          if (A(j).charAt(i) > A(j + 1).charAt(i)) {
            result = result + 1
            loop.break()
          }
        }
      }
    }
    return result
  }
```
