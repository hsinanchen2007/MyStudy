1,直接利用scala提供的工具计算
```

object Solution {
  def reverse(x: Int): Int = {
    var y = 0
    if (x > 0) {
      val b = x.toLong.toString.reverse.toLong
      if (b <= Int.MaxValue) {
        y=b.toInt
      }
    }
    if(x<0){
      val b = (x.toLong.abs).toString.reverse.toLong * -1
      if(b>=Int.MinValue){
        y=b.toInt
      }
    }
    y
  }
}
```
