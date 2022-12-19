突然觉得rust.slice.[idx..].sort有点优雅
```
impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        if nums.len() <= 1 {
            return;
        }
        if nums.len() == 2 {
            if nums[1] > nums[0] {
                nums.swap(0, 1);
            }
            return;
        }
        let mut min_i = 0;
        let mut min_swap_j = -1;
        for i in (1..nums.len()).rev() {
            for j in (0..i).rev() {
                if nums[i] > nums[j] {
                    if j as i32 > min_swap_j {
                        min_swap_j = j as i32;
                        min_i = i;
                        break;
                    }
                }
            }
        }
        if min_swap_j  > -1 {
            nums.swap(min_i, min_swap_j as usize);
            nums[min_swap_j as usize + 1..].sort();
            return;
        }
        nums.sort();
    }
}
```
