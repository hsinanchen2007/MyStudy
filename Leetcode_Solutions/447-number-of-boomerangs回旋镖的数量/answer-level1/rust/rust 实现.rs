```rust 
use std::collections::{HashMap};

impl Solution {
    fn dis(a:&Vec<i32>,b:&Vec<i32>) -> u64{
        ((a[0]-b[0]).pow(2)+(a[1]-b[1]).pow(2)) as u64
    }

    pub fn number_of_boomerangs(points: Vec<Vec<i32>>) -> i32 {
        let mut hm = HashMap::new();
        let mut res=0;
        for i in 0..points.len(){
            hm.clear();
            for j in 0..points.len(){
                let d = Solution::dis(&points[i],&points[j]);
                if i==j{
                    continue;
                }

                if hm.get(&d).is_some(){
                    let v = hm.get(&d).unwrap();
                    res += v*2;
                    *hm.get_mut(&d).unwrap()=v+1;
                } else{
                    hm.insert(d,1);
                }
            }
        }
        res
    }
}
```