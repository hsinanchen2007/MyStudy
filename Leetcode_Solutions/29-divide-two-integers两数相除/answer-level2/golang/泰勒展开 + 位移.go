### 解题思路
泰勒展开： dividend = (2^0 + 2^1 + ... + 2^n) * divisor

### 代码

```golang
func divide(dividend int, divisor int) int {
    cnt := 0
    sign := 1
    if dividend < 0 {
        sign = -sign
        dividend = -dividend
    }
    if divisor < 0 {
        sign = -sign
        divisor = -divisor
    }

    max_int := 2147483647
    p_ds, t_dv := 1, divisor
    for ; (divisor<<1) < dividend ; divisor, p_ds = divisor << 1, p_ds << 1 {}

    for t_dv <= dividend {
        dividend, cnt = dividend - divisor, cnt + p_ds 
        for divisor > dividend {
            divisor, p_ds = divisor >> 1, p_ds >> 1 
        } 
    }

    if sign < 0 && cnt > max_int {
        return -(max_int + 1)
    }
    if cnt > max_int {
        cnt = max_int
    }

    return cnt * sign
    

}
```