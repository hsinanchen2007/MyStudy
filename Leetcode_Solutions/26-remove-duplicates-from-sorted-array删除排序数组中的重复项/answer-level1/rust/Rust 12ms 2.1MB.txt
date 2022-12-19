### 解题思路
![image.png](https://pic.leetcode-cn.com/8a59cd1a77b31bcbb395ba79455035895401828de2df562c96b123fa38351428-image.png)


### 代码

```rust
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut i = 1;
        while i < nums.len() {
            if nums[i - 1] == nums[i] {
                nums.remove(i);
            } else {
                i += 1;
            }
        }
        nums.len() as i32
    }
}

```