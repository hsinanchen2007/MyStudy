### 解题思路
执行用时:340ms  内存消耗:41.7MB
直接使用暴力方法，先定义一个与原数组容量相同的数值，遍历原数组，并将原数组每一个值进行平方，并赋值给新的数组。新产生的数组是无序的，调用原生API，进行排序即可。

### 代码

```kotlin
class Solution {
    fun sortedSquares(A: IntArray): IntArray {
        val n = A.size
        val a = IntArray(n)
        for(i in A.indices){
            a[i] = A[i]*A[i]
            i.inc()
        }
        a.sort()
        return a
    }
}
```