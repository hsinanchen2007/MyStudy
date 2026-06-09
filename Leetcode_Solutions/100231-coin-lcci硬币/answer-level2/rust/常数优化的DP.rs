f[i][j]表示前i个硬币组成j有多少种方法。
由于只用1组成任何值都只有一种方法，所以硬币一那一维可以省掉

```rust
use std::cmp::min;

impl Solution {
    pub fn ways_to_change(n: i32) -> i32 {
        let mut f = vec![vec![0;n as usize+1]; 4];
        let un = n as usize;
        const m : i64 = 1000000007;
        let d = [5,10,25];
        for i in 0..3 {
            f[i][0] = 1;
        }
        for j in 1..5 {
            f[0][j] = 1;
        }
        for j in 5..=un {
            f[0][j] = 1+f[0][j-5];
        }
        for i in 1..3 {
            for j in 1..=min(d[i]-1 as usize, un) {
                f[i][j] = f[i-1][j];
            }
            for j in d[i] as usize..=un {
                f[i][j] = (f[i-1][j]+f[i][j-d[i] as usize])%m;
            }
        }
        f[2][un] as i32
    }
}
```