嗨, 别谈了, 作为一个新手, 通过编译都难
```rust
use std::rc::Rc;
use std::cell::RefCell;

fn stat_children (node: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    match node {
        Some(rc) => {
            rc.as_ref().borrow().val
        },
        None => {0},
    }
}

fn stat (node: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    match node {
        Some(rc) => {
            let tn = rc.as_ref().borrow(); 
            stat_children(tn.left.clone())+stat_children(tn.right.clone())
        },
        None => {0},
    }
}


impl Solution {
    pub fn sum_even_grandparent(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut node = root;
        match node {
            Some(rc) => {
                let tn = rc.as_ref().borrow();
                let v = tn.val;
                let local_sum = if v%2 == 0 { 
                    stat(tn.left.clone())
                    +stat(tn.right.clone())
                } else {0};
                local_sum 
                + Solution::sum_even_grandparent(tn.left.clone()) 
                + Solution::sum_even_grandparent(tn.right.clone())
            },
            None => {0},
        }
    }
}
```
