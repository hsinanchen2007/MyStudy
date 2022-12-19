### 解题思路
此处撰写解题思路

### 代码

```golang
func canThreePartsEqualSum(A []int) bool {
    sumA := 0
    for _,i := range A{
        sumA += i
    }
    if sumA % 3 != 0{
        return false
    }
    sumA = sumA / 3
    curSum := 0
    res := 0
    for i := range A{
        curSum += A[i]
        if curSum == sumA{
            res +=1
            curSum = 0
        }
    }
    return res > 2
}
```