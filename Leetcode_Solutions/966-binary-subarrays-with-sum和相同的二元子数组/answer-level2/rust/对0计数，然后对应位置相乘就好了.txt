```rust
impl Solution {
    pub fn num_subarrays_with_sum(a: Vec<i32>, s: i32) -> i32 {
        if a.len() == 0{
            return 0;
        }
        let mut zeros = vec![];
        let mut zc = 1;
        // 对0计数，两个1之间0的数目+1
        // 左右两边也要计数，没有0就记为1
        //[1,0,1,0,1] => [1,2,2,1]
        for x in a.iter() {
            if *x == 1 {
                zeros.push(zc);
                zc = 1;
            } else {
                zc += 1;
            }
        }
        zeros.push(zc);

        let mut res = 0;
        // 对应位置0的个数相乘，如果s为0，我们只找0的组合个数
        for i in 0..zeros.len()-s as usize{
            if s == 0{
                res += zeros[i]*(zeros[i]-1)/2;
            } else {
                res += zeros[i]*zeros[i+s as usize];
            }
        }
        res
    }
}

```
