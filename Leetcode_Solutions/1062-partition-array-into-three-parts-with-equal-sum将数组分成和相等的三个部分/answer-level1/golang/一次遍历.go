采用俩辅助变量记录当前分段的总和，跟分段次数
```python
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3 != 0:
            return False 
        target = total / 3
        f, count = 0, 0
        for i in range(len(A)):
            f += A[i]
            if f == target:
                f = 0
                count += 1
                if count == 2 and i < len(A) - 1:
                    return True
        return False
```
```golang
func canThreePartsEqualSum(A []int) bool {
    t := 0
    for i := 0; i < len(A); i++ {
        t += A[i]
    }
    if t % 3 != 0 {
        return false
    }
    tar := t / 3
    f, c := 0, 0
    for i := 0; i < len(A); i++ {
        f += A[i]
        if f == tar {
            f = 0
            c += 1
            if c == 2 && i < len(A) - 1 {
                return true
            }
        }
    }
    return false
}
```
