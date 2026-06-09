### 解题思路
见代码，方法不唯一

### 代码

```rust
impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut sum = 0i32;
        let mut arr: Vec<i32> = vec![0; n as usize];
        
        for i in 0..(n-1) {
            arr[i as usize] = i + 1; // 1 -- (n-1)
            sum += arr[i as usize];
        }
        arr[n as usize - 1] = 0 - sum; // 最后一位数是前面所以数和的相反数

        (arr)
    }
}
```