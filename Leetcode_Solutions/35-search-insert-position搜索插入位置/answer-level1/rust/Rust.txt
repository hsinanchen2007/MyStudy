标准库函数直接一行：

```Rust
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        nums.binary_search(&target).unwrap_or_else(|x| x) as i32
    }
}
```

自己写二分：
```Rust
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let (mut left, mut right) = (0, nums.len() - 1);

        while left <= right {
            let mid = (left + right) / 2;
            if target == nums[mid] { return mid as i32; } 
            else if target > nums[mid] { left = mid + 1; } 
            else {
                if mid == 0 { break; }
                right = mid - 1;
            }
        }

        left as i32
    }
}
```

都是0ms，2.1MB

![image.png](https://pic.leetcode-cn.com/31bf1c873c5eae4eb8f9e86fd6df244c7e79f8e51cca2f37dfe1d3d8d98a2275-image.png)
