递归，将分子和分母颠倒
a + 1/b = (a * b + 1)/b, 那么 1/(a + 1/b) = b/(a*b+1)
先计算最后一个值，然后每次将分子和分母调换返回。

```
func fraction(cont []int) []int {
    v1, v2 := f(cont)
    return []int{v2, v1}
}

func f(cont []int) (int, int) {
    if len(cont) == 1 {
        return 1, cont[0]
    }
    v1, v2 := f(cont[1:])
    return  v2, cont[0] * v2 + v1
}
```
