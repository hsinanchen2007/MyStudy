
![image.png](https://pic.leetcode-cn.com/e55cfaa40f10fa065d3ac2928e8335d12d1cae1c246c674db5bc3c35e741adaf-image.png)

```rust
impl Solution {
    pub fn min_moves2(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut min_moves = 0;
        for n in nums.iter() {
            min_moves += (nums[nums.len() / 2] - n).abs();
        }
        min_moves
    }
}
```

