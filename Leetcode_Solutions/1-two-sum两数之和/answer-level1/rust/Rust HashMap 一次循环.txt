```
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let len = nums.len();
        let mut m: HashMap<i32,i32> = HashMap::new();
        let mut ans = vec![];

        for i in 0..len {
            let remain = target - nums[i];
            m.entry(nums[i]).or_insert(i as i32);
            if m.contains_key(&remain) {
                if let Some(val) = m.get(&remain) {
                    if i as i32 != *val {
                        ans.push(*val);
                        ans.push(i as i32);
                        break;
                    }
                }                
            } 
        }
        ans
    }
}
```
