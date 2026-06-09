```
use std::i32::MAX;
impl Solution {
       pub fn merge(v1: &mut Vec<i32>, l1: i32, v2: &mut Vec<i32>, l2: i32) {
        if v1.len() < (l1+l2) as usize {
            panic!("The capacity of v1 is not enough for merging ");
            return;
        }        
        if l1 == 0 && l2 > 0 {
            *v1 = v2.to_vec();
            return;
        }
        if l2 == 0 {
            return;
        }
        
        let mut i = l1 as usize - 1;
        let mut j = l2 as usize - 1;
        let bounded = MAX as usize;

        for k in (0..l1 + l2).rev() {
            if j == bounded || i != bounded && v1[i] > v2[j] {
                v1[k as usize] = v1[i];
                i = if i == 0 { bounded } else { i - 1 };
            } else {
                v1[k as usize] = v2[j];
                j = if j == 0 { bounded } else { j - 1 };
            }
        }
    }
}

```
