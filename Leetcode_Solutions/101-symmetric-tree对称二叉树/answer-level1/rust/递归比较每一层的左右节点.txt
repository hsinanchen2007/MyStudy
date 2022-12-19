


### 代码

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            Some(node) => {
                let mut n_borrow = node.borrow_mut();
			    Self::check(n_borrow.left.take(), n_borrow.right.take())
            },
            None => true,
        }	   
    }
    fn check(left: Option<Rc<RefCell<TreeNode>>>, right: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (left, right) {
            (None, None) => true,
            (Some(l), Some(r)) => {
                let mut l_borrow = l.borrow_mut();
			    let mut r_borrow = r.borrow_mut();
                if(l_borrow.val != r_borrow.val) {
                    return false;
                }
                Self::check(l_borrow.left.take(), r_borrow.right.take()) 
                    && Self::check(l_borrow.right.take(), r_borrow.left.take())
                },
            _ => false,
        }
    }

}
```