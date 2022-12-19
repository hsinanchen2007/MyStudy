### 解题思路
![image.png](https://pic.leetcode-cn.com/084712c124946b02ed7e23fbbe635251f2095ec2cf96bfccc2f8fbfa354f3cb8-image.png)

### 代码

```rust
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i = 0;
        while i < nums.len() {
            if nums[i] == val {
                nums.remove(i);
            } else {
                i += 1;
            }
        }
        nums.len() as i32
    }
}

```