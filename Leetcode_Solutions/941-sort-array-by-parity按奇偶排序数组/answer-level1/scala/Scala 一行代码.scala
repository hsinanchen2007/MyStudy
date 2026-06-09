### 代码

```scala
object Solution {
    def sortArrayByParity(A: Array[Int]): Array[Int] = {
        A.filter(_%2==0) ++ A.filter(_%2==1)
    }
}
```