不停的过滤掉不包含target的一半，不停更新首尾索引。
```
impl Solution {
    fn dichoto(nums: &Vec<i32>, target: i32, start: usize, end: usize, from: &mut i32, to: &mut i32)  {
        let len = end - start;
        if len == 0 {
            return;
        }
        if nums[end - 1] < target  || nums[start] > target {
            return;
        }
        if nums[start] == target && nums[end - 1] == target {
            if *from ==  -1 || *from > start as i32 {
                *from = start as i32;
            }
            if *to ==  -1 || *to < start as i32 {
                *to = (end - 1) as i32;
            }
            return;
        }

        Self::dichoto(nums, target, start, start + len / 2, from, to);
        Self::dichoto(nums, target, start + len / 2, end , from, to);
        
    }
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut from = -1;
        let mut to = -1;
        Self::dichoto(&nums, target, 0, nums.len(), &mut from, &mut to);
        vec![from, to]
    }
}
```
