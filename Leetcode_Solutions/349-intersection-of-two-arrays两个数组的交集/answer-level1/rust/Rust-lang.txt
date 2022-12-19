### 运行结果

![image.png](https://pic.leetcode-cn.com/37dca607b3baa95b4fabe3aca16379b0417ac758018819ba6a80cdded19adc08-image.png)

### 解题思路

依次查找，没有任何优化。用了HashSet

### 代码

```rust
use std::collections::HashSet;
impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut set: HashSet<i32> = HashSet::new();
        for item in nums1 {
            if nums2.contains(&item) {
                set.insert(item);
            }
        }
        let mut ans: Vec<i32> = Vec::new();
        for item in set {
            ans.push(item);
        }
        (ans)
    }
}
```