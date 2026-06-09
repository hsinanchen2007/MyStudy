### 代码
#### 方法1
```scala
object Solution {
    def numJewelsInStones(J: String, S: String): Int = {
         S.toCharArray.map(c => if(J.contains(c)) 1 else 0).sum
    }
}
```
#### 方法2
``` scala
object Solution {
    def numJewelsInStones(J: String, S: String): Int = {
         S.toCharArray.filter(J.contains(_)).length
    }
}
```
#### 方法3
``` scala
  def numJewelsInStones(J: String, S: String): Int = {
    var count = 0
    S.toCharArray.foreach(c =>
      if(J.contains(c)) count += 1
    )
    count
  }
```