首先我们可以确定的是这样的元素最多只有两个，这个就不证明了，所以我们需要两组变量来存储值与出现次数
```rust
        let mut first = 0i32;
        let mut second = 0i32;
        let mut first_count = 0i32;
        let mut second_count = 0i32;
```
这样当数组遍历完毕的时候剩下的一定是出现次数最多的两个数值，那么此时我们就可以比较出现次数是否大于n/3并得到结果。
```rust
use std::convert::TryFrom;
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut first = 0i32;
        let mut second = 0i32;
        let mut first_count = 0i32;
        let mut second_count = 0i32;
        let mut result:Vec<i32> = Vec::new();
        for n in &nums {
            if *n == first {
                first_count += 1;
            } else if *n == second {
                second_count += 1;
            } else if first_count == 0i32 {
                first = *n;
                first_count = 1;
            } else if second_count == 0i32{
                second = *n;
                second_count = 1;
            } else {
                first_count -= 1;
                second_count -= 1;
            }
        }
        first_count = 0;
        second_count = 0;
        for n in &nums {
            if *n == first {
                first_count += 1;
            } else if *n == second {
                second_count += 1;
            }
        }
        let active_len = i32::try_from(nums.len()).unwrap()/3;
        if first_count > active_len {
            result.push(first);
        }
        if second_count > active_len {
            result.push(second);
        }
        return result;
    }
}
```
