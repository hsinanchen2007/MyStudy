```rs
impl Solution {
    pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
        let mut v = vec![-1;100];
        for (&n, &i) in nums.iter().zip(&index) {
            let i = i as usize;
            v.copy_within(i..99, i+1);
            v[i] = n;
        }
        v.retain(|&x| x != -1);
        v
    }
}
```

由题目可知道数组总长度不超过 100, 每次新增只需要把 i 到 99 的数据向右移动一位即可.

`copy_within` 使用的是 memmove, 所以速度很快.