### 运行结果

![image.png](https://pic.leetcode-cn.com/5de6fa8c8a39b7c961051fbbc7f284d4d7f6127871da1f49e44b562198a7ce61-image.png)


### 代码

```rust
impl Solution {
    pub fn array_pair_sum(nums: Vec<i32>) -> i32 {
        let mut numbers = nums;
        let mut sum = 0i32;
        let mut index = 0usize;
        numbers.sort(); // 排序
        loop {
            sum += numbers[index]; // 偶数位数求和，从0开始
            index += 2;
            if index == numbers.len() {
                break;
            }
        }
        (sum)
    }
}
```