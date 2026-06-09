N&1得到最低位n，n^1取反
计算完右移，循环即可
```golang
func bitwiseComplement(N int) int {
    if N == 0 {
        return 1
    }
    res := 0
    for i:=1; N > 0; i*=2 {
		res += (N&1^1) * i
		N >>= 1
	}
    return res
}
```