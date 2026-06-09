```
class Solution {
    fun maxRotateFunction(A: IntArray): Int {
        val F = A.clone()
        for (i in 0..F.size - 1) {
            F[i] = getSum(A, i)
        }
        return F?.max() ?: 0
    }
    
    fun getSum(A: IntArray, start:Int):Int{
        var sum = 0
        for (i in 0..A.size -1) {
            sum += A[i] * ((i+start)%A.size)
        }
        return sum
    }
}
```

执行结果：
通过
显示详情
执行用时 :
2476 ms
, 在所有 Kotlin 提交中击败了
100.00%
的用户
内存消耗 :
39.2 MB
, 在所有 Kotlin 提交中击败了
100.00%
的用户