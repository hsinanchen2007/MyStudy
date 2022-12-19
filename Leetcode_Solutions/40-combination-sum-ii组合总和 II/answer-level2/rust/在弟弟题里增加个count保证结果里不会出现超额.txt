```
use std::collections::HashSet;
use std::collections::HashMap;
impl Solution {
    fn get_count(v: &Vec<i32>, target: i32) -> i32 {
        let mut count = 0;
        for &val in v {
            if val > target {
                break
            }
            if val == target {
                count += 1;
            }
        }
        count
    }
    pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut all_ans: Vec<HashSet<Vec<i32>>> = vec![HashSet::new(); target as usize + 1];
        let mut candidates = candidates;
        candidates.sort();
        let mut num_count: HashMap<i32, i32> =  HashMap::new();
        for &v in &candidates {
            let counter = num_count.entry(v).or_insert(0);
            *counter += 1;
        }
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
                        if Self::get_count(&rec, val) >= *(num_count.get(&val).unwrap()) {
                            continue;
                        }
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
