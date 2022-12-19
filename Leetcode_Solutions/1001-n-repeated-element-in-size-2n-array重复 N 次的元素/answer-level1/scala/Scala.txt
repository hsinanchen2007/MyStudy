### 解题思路
因为有一半是相同的，所以情况只有三种，相邻或者不相邻时第一个或者第二个

### 代码

```scala
object Solution {
    def repeatedNTimes(A: Array[Int]): Int = {
         for(i<- 0 until A.length-1){
      if(A(i)==A(i+1))
       return A(i)
    }
    if(A(1)==A(3)) return A(1)
    A(0)   
    }
}
```