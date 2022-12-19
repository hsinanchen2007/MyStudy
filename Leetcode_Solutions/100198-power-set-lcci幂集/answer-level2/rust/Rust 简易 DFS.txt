0 ms; 2.2 MB
```rs
impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut r = vec![];
        let mut jobs = vec![(0, vec![])];
        while !jobs.is_empty() {
            let (i, base) = jobs.pop().unwrap();
            r.push(base.clone());
            for j in i..nums.len() {
                let mut b = base.clone();
                b.push(nums[j]);
                jobs.push((j+1, b));
            }
        }
        r
    }
}
```