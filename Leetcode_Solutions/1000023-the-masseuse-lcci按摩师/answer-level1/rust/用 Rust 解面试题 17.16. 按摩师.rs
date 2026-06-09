## 解题思路
动态规划。dp[i + 1] 就是接第 i 个预约时，最长的总预约时间。因为不能接受相邻的预约，索引 dp[i + 1] 应该等于 dp[0..= i - 1] 数组里面的最大值加上第 i 个预约的分钟数 nums[i]。考虑极限情况，dp[0] = 0，dp[1] = nums[0]. 遍历预约请求数组 nums，最后 dp 的最大值就是最长的总预约时间。

用到的方法：
* 对于数组切片，调用 iter() 方法，返回一个 Struct std::slice::Iter 类型，标准库对 Iter<T> 实现了 Trait std::iter::Iterator，所以可以调用其中的 max() 方法返回一个 Option 类型，接着调用 unwrap() 方法，返回 Some(v) 里面的值 v
* 对于 Struct std::vec::Vec 类型，标准库对其实现了 Trait std::ops::Deref，返回切片的引用 &[T]，显式的用 * 解引用后对切片进行上述操作即可。

## 完整代码
```Rust
impl Solution {
    pub fn massage(nums: Vec<i32>) -> i32 {
        let mut dp = vec![0; nums.len() + 1];
        for i in 0..nums.len() {
            dp[i + 1] = if i > 0 {
                dp[0..= i - 1].iter().max().unwrap() + nums[i]
            } else { 
                nums[i]
            }
        }
        *dp.iter().max().unwrap()
    }
}
```