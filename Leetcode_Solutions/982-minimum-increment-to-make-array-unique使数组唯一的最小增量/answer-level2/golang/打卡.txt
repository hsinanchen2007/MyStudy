### 解题思路
排序

### 代码

```golang
func minIncrementForUnique(A []int) int {
    move := 0
    if len(A) < 2 {
        return 0
    }
    sort.Ints(A)
    num := A[0]
    for i:=1;i<len(A);i++{
        if A[i] == num {
            move++
            num++
        } else if A[i] < num {
            move += num - A[i] + 1
            num++
        }  else {
            num = A[i]
        }
    }
    return move
}
```