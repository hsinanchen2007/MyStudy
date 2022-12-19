```rust
use std::collections::{HashMap};
impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let hm:HashMap<_,_> = list1.iter().enumerate().map(|e|(e.1,e.0)).collect();
        let cons:Vec<_> = list2.iter().enumerate().filter(|e|hm.get(e.1).is_some()).map(|e|(e.0+hm.get(e.1).unwrap(),e.1) ).collect();
        let minIdxSum = cons.iter().map(|e|e.0).fold(usize::max_value(),|acc,cur| if cur<acc {cur} else {acc});
        cons.iter().filter(|e|e.0 == minIdxSum).map(|e| e.1.clone()).collect::<Vec<_>>()
    }
}
```