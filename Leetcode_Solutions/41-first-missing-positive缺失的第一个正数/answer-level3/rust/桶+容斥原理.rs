### 解题思路
桶+容斥原理

### 代码

```rust
impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        if nums.is_empty() { return 1; }
        let len = nums.len();
        for i in 0..len {
            loop {
                let n = nums[i];
                if n == (i + 1) as i32 {
                    break;
                } else if 1 <= n && n <= len as i32 {
                    if nums[(n - 1) as usize] == n {
                        nums[i] = -1;
                        break;
                    }
                    nums.swap(i, (n - 1) as usize);
                } else {
                    nums[i] = -1;
                    break;
                }
            }
        }
        for (i, n) in nums.iter().enumerate() {
            if *n == -1 {
                return (i + 1) as i32;
            }
        }
        return (len + 1) as i32;
    }
}
```