### 解题思路
第二次学习终于理解了一些

### 代码

```golang
func shortestSubarray(A []int, K int) int {
    // 前缀和
    var sumArr []int
    sumArr = append(sumArr, 0)
    for i := 0; i < len(A); i++ {
        sumArr = append(sumArr, sumArr[i] + A[i])
    }

    // 返回结果
    var res = len(A) + 1
    // 下标数组
    var indexArr []int
    for i := 0; i < len(sumArr); i++ {
        // 保证sumArr是递增的，把负数的去掉
        for {
            // 正常升序的就没事，遇到比当前大的，就把前面大的全去掉
            if len(indexArr) == 0 || sumArr[i] > sumArr[indexArr[len(indexArr) - 1]] {
                break
            }
            indexArr = indexArr[:len(indexArr) - 1]
        }
      
        // 找到最小的数组
        for {
            // 阶段和还不到k，继续下移
            if len(indexArr) == 0 || sumArr[i] < sumArr[indexArr[0]] + K {
                break
            }
            // 如果和已经达到了K
            if res > i - indexArr[0] {
                res = i - indexArr[0]
            }
            // 和太大的时候把下面的移除
            indexArr = indexArr[1:]
        }
        // 把下标加进去
        indexArr = append(indexArr, i)
    }
    if res == len(A) + 1 {
        return -1
    }
    return res
}
```