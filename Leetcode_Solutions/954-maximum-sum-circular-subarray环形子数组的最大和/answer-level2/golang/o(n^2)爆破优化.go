![屏幕快照 2019-08-09 17.10.57.png](https://pic.leetcode-cn.com/cd513b07616de24fe1076ee09019fd5f195fe2db2ec9c985836b115359ed5d7a-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-08-09%2017.10.57.png)

直接爆破，做点优化即可

```
func maxSubarraySumCircular(A []int) int {
    lenth := len(A)
    max := A[0]
    A = append(A,A...)//环形条件限制
    for l:=0;l<lenth;l++{
        sum := 0
        for r := l;r-l<lenth ;r++{
            sum += A[r]
            if sum < 0 && sum < max{//在这一步做了裁剪，如果到这部分仍然是小于的，直接跳过这个l；同时为了防止全负情况或a[0]为负的情况，做了个简单sum校验
                break
            } 
            if sum > max {
                max = sum
            }
        }
    }
    return max
}
```
