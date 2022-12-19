### 代码

```rust
impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        let len: usize = nums.len();
        for i in (0..len - 1).rev(){
            if nums[i] < nums[i + 1] {
                for j in (i + 1..len) {
                    if j == len - 1 || (nums[i] < nums[j] && nums[i] >= nums[j + 1]) {
                        let mut temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        nums[i+1..len].reverse();
                        return;
                    }
                }
            }
        }
        nums.reverse();
    }
}


```