### 解题思路
双端队列，插入前检查队尾数据与当前值大小，比当前值小的都从队尾弹出，保证队首始终为
窗口内的最大值

### 代码

```rust

use std::collections::VecDeque;

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut result: Vec<i32> = vec!();
        if nums.len() == 0 || k == 0 || k > (nums.len() as i32){
            return result;
        }
        let mut queue: VecDeque<i32> = VecDeque::new();
        for i in 0..nums.len() {
            //清理队尾数据 这一步保证了大小的排序 队首 > next > next
            while let Some(j) = queue.back() {  
                if nums[i] > nums[*j as usize] {
                    queue.pop_back();
                } else {
                    break;
                }
            }
            let i: i32 = i as i32;
            //当前下标入队尾
            queue.push_back(i);

            //当前队首是否过期
            if *queue.front().unwrap() == i-k {
                queue.pop_front();
            }
            //add当前滑动窗口的最大值
            if i >= k-1 {
                result.push(nums[*queue.front().unwrap() as usize]);
            }
        }
        result
    }
}
```