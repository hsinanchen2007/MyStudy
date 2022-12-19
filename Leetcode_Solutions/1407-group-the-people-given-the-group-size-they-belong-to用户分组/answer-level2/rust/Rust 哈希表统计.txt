4 ms ; 2.1 MB
```rs
use std::collections::HashMap;

impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let mut r = vec![];
        let mut map = HashMap::new();

        for (i, x) in group_sizes.iter().enumerate() {
            let e = map.entry(x).or_insert(vec![]);
            e.push(i as i32);
            if e.len() == *x as usize {
                r.push(e.clone());
                map.remove(x);
            }
        }

        r
    }
}
```