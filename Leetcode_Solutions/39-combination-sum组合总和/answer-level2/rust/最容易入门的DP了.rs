```
use std::collections::HashSet;
impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut all_ans: Vec<HashSet<Vec<i32>>> = vec![HashSet::new(); target as usize + 1];
        let mut candidates = candidates;
        candidates.sort();

        for i in 1..(target as usize + 1) {
            for j in 0..candidates.len() {
                let val = candidates[j];
                if val > i as i32 {
                    break;
                }
                let dif = i as i32 - val;
                if dif == 0 {
                    all_ans[i].insert(vec![val]);
                } else {
                    let cl = all_ans[dif as usize].clone();
                    for mut rec in cl {
                        rec.push(val);
                        rec.sort();
                        all_ans[i].insert(rec);
                    }
                }
            }
        }
        all_ans.remove(target as usize).into_iter().collect()
    }
}
```
