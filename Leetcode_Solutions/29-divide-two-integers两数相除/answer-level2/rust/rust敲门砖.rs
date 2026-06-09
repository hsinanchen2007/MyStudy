憨憨减1超时了。

```
impl Solution {
   fn divide_posi(mut dividend: i32, divisor: i32) -> i32 {
        let mut ret = 0;
        for i in (0..32).rev() {
            if (dividend >> i) >= divisor {
                ret += 1 << i;
                dividend -= divisor << i;
            }
        }
        ret
    }
    pub fn divide(dividend: i32, divisor: i32) -> i32 {
        if divisor == 1   {
            return  dividend;
        }
        if divisor == -1 && dividend != std::i32::MIN{
            return -dividend;
        }
        if divisor == std::i32::MIN {
            if dividend == std::i32::MIN {
                return 1;
            } else {
                return 0;
            }
        }

        let mut ret = 0;
        let mut nega = true;
        let mut dividend  = dividend;

        if dividend == std::i32::MIN {
            ret += 1;
            if divisor < 0 {
                dividend -= divisor;
            } else {
                dividend += divisor;
            }
        } 

        let dividend = if dividend < 0 { nega = false; - dividend } else { dividend };
        let divisor = if divisor < 0 { nega = !(nega ^ false); - divisor } else { divisor };
        let tmp = Self::divide_posi(dividend, divisor);
        if tmp == std::i32::MAX {
            return std::i32::MAX;
        }
        ret += tmp;
        if nega == false {
            -ret
        } else {
            ret
        }
    }
}
```
