因为一共只有30个数，可以用 `u32` 类型来存动态规划数据。

`dp[sum]` 表示这个和可以用原数组中几个数加起来得到。例如 `0b10110` 表示 可以用原数组中 1 个数，2 个数，或者 4 个数加起来得到。

最后检验所有的 sum 中是否有满足要求的

```
impl Solution {
    pub fn split_array_same_average(a: Vec<i32>) -> bool {
      let total_sum = a.iter().sum::<i32>() as usize;
      let mut dp: Vec<u32> = vec![0; total_sum + 1];
      dp[0] = 1;
      for num in &a {
        let num = *num as usize;
        for sum in (num..=total_sum).rev() {
          dp[sum] |= dp[sum - num] << 1;
        }
      }
      for sum in 1..dp.len()-1 {
        let len = {
          let s = sum * a.len();
          if s % total_sum != 0 {
            continue;
          }
          s / total_sum
        };
        if dp[sum] & (1 << len) != 0 {
          return true;
        }
      }
      false
    }
}
```
