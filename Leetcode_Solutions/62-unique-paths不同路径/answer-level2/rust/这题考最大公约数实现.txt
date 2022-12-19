组合为C(m+n-2, n - 1)
直接求阶乘可能会溢出， 先将待乘的数分别除去最大公约数，最后累乘。
```
impl Solution {
    fn gcd(x: i32, y: i32) -> i32 {
        let mut x = x;
        let mut y = y;
        while x > 0 && y > 0 {
            if x > y {
                x = x % y;
            } else {
                y = y % x;
            }
        }
        if x > y { x } else { y }
    }
    fn combin(m: i32, n: i32) -> i32 {
        let mut v1: Vec<i32> = ((n + 1)..(m + 1)).collect();
        let mut v2: Vec<i32> = (1..(m - n + 1)).collect();
        while let Some(t) = v2.last_mut() {
            for i in (0..v1.len()).rev() {
                let g = Self::gcd(v1[i], *t);
                v1[i] /= g;
                if g == *t {
                    v2.pop();
                    break;
                } else {
                    *t /= g;
                }
            }
        }
        v1.iter().fold(1, |acc, x| acc * x)
    }
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        Self::combin(m + n - 2, n - 1)
    }
}
```
