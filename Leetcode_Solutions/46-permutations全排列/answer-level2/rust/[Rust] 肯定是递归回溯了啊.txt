# 如果用宏，能实现吗？该怎么写。。
# 不是宏递归，是宏生成对应数量的嵌套循环。
```
impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        if nums.len() > 1 {
            for i in 0..nums.len() {
                let mut num_clone = nums.clone();
                let curent = num_clone.remove(i);
                let tmp = Solution::permute(num_clone);
                for mut v_internal in tmp {
                    v_internal.insert(0,curent);
                    res.push(v_internal)
                }
            }
        } else {
            res.push(vec![nums[0]]);
        }
        res
    }
}
```
