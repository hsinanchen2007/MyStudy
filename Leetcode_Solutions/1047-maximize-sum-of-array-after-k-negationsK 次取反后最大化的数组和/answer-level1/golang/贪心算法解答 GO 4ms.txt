解题思路。
A【3,4,-2,-3,-1] K = 4
- 先将 A 排序 [-3,-2,-1,3,4] 
- 然后利用贪心算法，先将最小的进行反转，-3 反转后为 3 大于它的下一个 -2 所以接下来反转 -2 
- -2 反转后 2 大于 -1 所以继续反转 -1 
- 反转 -1 为 1 后 检查发现小于下一个 3 所以继续反转 -1 即可, 因为后面都是正数了。

```go []
func largestSumAfterKNegations(A []int, K int) int {
    //排序
    sort.Ints(A)
    ans := 0
    i := 0
    for i < len(A) && K > 0 {
        A[i] = -A[i]
        //如果 反转后 数据比下一个还小。那么继续反转
        if A[i] > 0 && A[i] > A[i+1] {
            i++ 
        }
        K--
    }
    for _, v := range A {
        ans += v
    }
    return ans
}
```