
```rust
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::{HashMap};
impl Solution {
    pub fn dfs(node:Option<Rc<RefCell<TreeNode>>>,hp:&mut HashMap<i32,u32>)->i32{
        match node{
            Some(m)=>{
                let mut sum=m.borrow().val;
                sum += Solution::dfs(m.borrow().left.clone(),hp);
                sum += Solution::dfs(m.borrow().right.clone(),hp);
                let pC = hp.entry(sum).or_insert(0);
                *pC += 1;
                sum
            },
            None=> 0
        }
    }
    
    pub fn find_frequent_tree_sum(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut hm: HashMap<i32,u32>=HashMap::new();
        Solution::dfs(root,&mut hm);
        let mut unSort:Vec<_> =  hm.iter().collect();
        unSort.sort_by(|a,b|(b.1).cmp(a.1));
        if unSort.len()<1{
            return vec![]
        }
        let max = unSort[0].1;
        unSort.iter().filter(|e|e.1==max).map(|e|*e.0).collect::<Vec<i32>>()
    }
}
```
