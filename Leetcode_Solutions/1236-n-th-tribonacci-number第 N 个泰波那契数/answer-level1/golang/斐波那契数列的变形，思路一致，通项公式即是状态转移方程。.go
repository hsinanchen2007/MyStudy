### 解题思路
此处撰写解题思路

### 代码

```golang
func tribonacci(n int) int {
    if n < 2 {
        return n
    }
    if n == 2 {
        return 1
    }
    a := make([]int,n)
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    for i := 3; i < n; i++ {
        a[i] = a[i-1] + a[i-2] + a[i-3]
    }
    return a[n-1] + a[n-2] + a[n-3]
}
```