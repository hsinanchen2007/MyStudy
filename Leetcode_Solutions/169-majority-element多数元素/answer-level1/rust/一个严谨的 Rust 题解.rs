在提交排行里看到的, 对于 Option 类型的运用太棒了.

```rs
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        // 用 None 表示没有找到 多数元素
        let mut curr_elem = None;
        let mut curr_count = 0;
        // 用 for 遍历, 排除了越界的可能
        for n in nums {
            match curr_elem {
                // 如果已找到多数元素, 对比新的元素, 继续计数
                Some(last) => {
                    if last == n {
                        curr_count += 1;
                    } else {
                        curr_count -= 1;
                        if curr_count==0 {
                            curr_elem = None;
                        }
                    }
                },
                // 如果没有多数元素, 当前元素即为多数元素
                None => {
                    curr_elem = Some(n);
                    curr_count += 1;
                }
            }
        }
        match curr_elem {
            Some(majority) => majority,
            None => panic!("no majority")
        }
    }
}
```