
![Screenshot from 2020-04-05 21-14-15.png](https://pic.leetcode-cn.com/d6e7000ee3b539444214b12be0985369b9cc646cab8761aa00fe20326688de8f-Screenshot%20from%202020-04-05%2021-14-15.png)


impl Solution {
    pub fn reverse(x: i32) -> i32 {
            let mut m:i64 = x as i64;
    let mut is_negative = false;
    if m < 0 {
        is_negative = true;
        m = 0 - m;
    }
    let mut base = 10;
    let mut y:i64 = 0;
    loop {
        y = y * base + m % base;
        m = m / base;
        if m == 0 {
            break;
        }
    }
    if is_negative {
        y= 0 - y;
    }
    if y>(std::i32::MAX as i64) || y< (std::i32::MIN as i64){
        return 0;
    }
    return y as i32;
    }
}