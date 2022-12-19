### 解题思路
被除数除数还有计数器都映射到负数去解，不需要处理正数那种边界情况。看起来判断最终结果正负号的地方可以再优化一下。 参照[@luca-zhao](/u/luca-zhao/)

### 代码

```rust
impl Solution {
    pub fn divide(dividend: i32, divisor: i32) -> i32 {
    let max = 2147483647;
    let min = -2147483648;
    let mut dividend = dividend;
    let mut divisor = divisor;
    let mut sign = true;
    if dividend == min && divisor == -1{
        return max;
    }
    if dividend > 0 && divisor<0{
        sign = false;
        dividend = -dividend;
    }
    else if dividend <0 && divisor>0 {
        sign = false;
        divisor = -divisor;
    }
    else if dividend>0 && dividend>0{
        dividend = -dividend;
        divisor = -divisor;
    }
    else if dividend==0 { return 0 }
    let mut count = 0;
    while dividend <= divisor{
        let mut c = -1;
        let mut div = divisor;
        loop {
            if div>min/2 && div+div > min/2 && dividend<=div+div{
                div = div + div;
                c = c + c;
            }
            else {
                dividend -= div;
                break
            }
        }
        count += c;
    }
    if sign==true{count = -count}
    return count
}
}
```