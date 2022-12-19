### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
            nums.sort();
    let mut res = nums[0] + nums[1] + nums[2];
    let length = nums.len() -2;
    for i in 0..length {
        if i != 0 && nums[i] == nums[i -1] {
            continue;
        }
        let(mut L, mut R) = (i+1, length + 1);
        while L < R {
            let cur = nums[i] + nums[L] + nums[R];
            if (cur - target).abs() < (res - target).abs() {
                res = cur;
            }
            if cur > target {
                R = R -1;
            }else if cur < target {
                L = L + 1;
            }else {
                return target;
            }
        }
    }
    res
    }
}
```