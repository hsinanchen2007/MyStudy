### 解题思路
两数相乘，可以转化为加法

### 代码

```golang
func multiply(A int, B int) int {
    if A < B {
        if A == 0 {
            return 0
        }
        return multiply(A-1, B) + B
    } else {
        if B == 0 {
            return 0
        }
        return multiply(A, B-1) + A
    }
}
```