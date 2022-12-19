### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def findTheDifference(s: String, t: String): Char = {
     var sum1,sum2=0
    for(i<-0 until s.length){
      sum1+=s(i).hashCode
    }
    for(i<-0 until t.length){
      sum2+=t(i).hashCode
    }
    (sum2-sum1).toChar   
    }
}
```