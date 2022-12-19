### 解题思路
![image.png](https://pic.leetcode-cn.com/5ffd8bbafada1947988c1b938ba6af4e418abb7ca537ebf533a23e1f1b1c850c-image.png)


### 代码

```rust
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut res = nums[0];

        for i in nums {
            if sum > 0 {
                sum += i;
            } else {
                sum = i;
            }
            res = std::cmp::max(res, sum);
        }
        res
    }
}
```