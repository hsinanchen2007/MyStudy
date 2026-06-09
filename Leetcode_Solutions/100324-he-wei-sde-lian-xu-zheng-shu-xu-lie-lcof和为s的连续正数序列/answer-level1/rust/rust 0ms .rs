```
impl Solution {
    pub fn find_continuous_sequence(target: i32) -> Vec<Vec<i32>> {
        let mut res = vec![];
        for i in 1..=target / 2 {
            let mut j = i + 1;
            let mut sum = i + j;
            while sum < target {
                j += 1;
                sum += j;
            }
            if sum == target {
                res.push((i..=j).collect());
            }
        }
        res
    }
}
```
