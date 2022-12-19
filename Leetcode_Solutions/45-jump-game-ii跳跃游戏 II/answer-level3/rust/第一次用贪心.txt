简单注释下贪心有效条件。
```
impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        // 贪婪算法: 当前选择时下一步选择能走到最远。
        // 单挑函数都可以使用贪婪算法。
        if nums.len() <= 1 {
            return 0;
        }
        if nums.len() == 2 {
            return 1;
        }
        let mut pos = 0;
        let mut step = 0;
        while pos < nums.len() - 1 {
            step += 1;
            let mut next = 0;
            let mut choose = 0;
            // 判断自己能否一步到达
            if pos + nums[pos] as usize >= nums.len() - 1 {
                return step;
            }
            // 不能选择下一步最远能达到
            for i in 1..(nums[pos] as usize + 1) {
                if pos + i + nums[pos + i] as usize > next {
                    next = pos + i + nums[pos + i] as usize ;
                    choose = pos + i;
                }
            }
            pos = choose;
        }
        step
    }
```
