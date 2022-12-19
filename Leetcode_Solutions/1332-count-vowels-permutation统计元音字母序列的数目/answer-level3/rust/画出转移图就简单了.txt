![图片1.png](https://pic.leetcode-cn.com/920dc8750c4292856fa990a2b492436c7665fdf55c59014969fd1801a8eb380f-%E5%9B%BE%E7%89%871.png)

```rust
impl Solution {
    pub fn count_vowel_permutation(n: i32) -> i32 {
        let mut count_n:[i64;5] = [1,1,1,1,1]; // a,e,i,o,u
        for _i in 1..n {
            let mut c_nn = [0,0,0,0,0];
            c_nn[0] = count_n[1] + count_n[2]+count_n[4];
            c_nn[1] = count_n[0] + count_n[2];
            c_nn[2] = count_n[1] + count_n[3];
            c_nn[3] = count_n[2];
            c_nn[4] = count_n[2] + count_n[3];
            for j in 0..5 {
                count_n[j] = c_nn[j]%10_0000_0007;
            }
        }
        let r:i64 = count_n.iter().sum::<i64>()%1000000007;
        r as i32
    }
}
```
