```
impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;
        let mut record: Vec<i32> = vec![1; n];
        for i in 1..m {
            for j in 1..n {
                    record[j] = record[j - 1] + record[j];
            }
        } 
        record[n - 1]
    }
}
```

