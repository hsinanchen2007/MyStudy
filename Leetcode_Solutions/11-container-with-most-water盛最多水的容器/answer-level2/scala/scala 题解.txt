![TIM图片20191014113552.png](https://pic.leetcode-cn.com/1306f194da3553c3bd2ae169569002b46b2225a8c9f19f5dd89282a1da0f5a4c-TIM%E5%9B%BE%E7%89%8720191014113552.png)

```scala
object Solution {
  def maxArea(height: Array[Int]): Int = {
    var area: Int = 0
    var r: Int = height.length - 1
    var l: Int = 0
    while (r > l) {
      area = math.max(area, math.min(height(l), height(r)) * (r - l))
      if (height(r) > height(l)) l = l + 1
      else r = r - 1
    }
    area
  }
}
```
