### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut candidate = -1;
        let mut count = 0;
        for num in nums{
            if num == candidate {
                count+=1;
            } else {
                count-=1;
                if count < 0 {
                    candidate = num;
                    count=1;
                }
            }
        }
        candidate
    }
}


```