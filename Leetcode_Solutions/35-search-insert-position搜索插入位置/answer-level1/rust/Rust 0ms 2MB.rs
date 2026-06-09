### 解题思路
![image.png](https://pic.leetcode-cn.com/e8dc7bea13598289f1e2f03b74058d05d76cd4cc9de897466be5a0b3063968c8-image.png)


### 代码

```rust
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut low: i32 = 0;
        let mut high: i32 = nums.len() as i32 - 1;
        let mut mid;

        while low < high {
            mid = (low + high) / 2;
            if nums[mid as usize] == target {
                return mid;
            }
            if nums[mid as usize] < target {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if target <= nums[low as usize] {
            return low as i32;
        }
        low + 1
    }
}
```