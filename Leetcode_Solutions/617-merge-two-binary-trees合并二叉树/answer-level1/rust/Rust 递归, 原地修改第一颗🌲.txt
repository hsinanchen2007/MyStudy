0 ms; 2.1 MB
```rs
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
    pub fn merge_trees(t1: Option<Rc<RefCell<TreeNode>>>, t2: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        fn mt(t1: &mut Option<Rc<RefCell<TreeNode>>>, t2: &Option<Rc<RefCell<TreeNode>>>) {
            if let Some(mut n1) = t1.as_ref() {
                if let Some(n2) = t2 {
                    let mut n1 = n1.borrow_mut();
                    let n2 = n2.borrow();
                    n1.val += n2.val;
                    mt(&mut n1.left, &n2.left);
                    mt(&mut n1.right, &n2.right);
                }
            } else {
                *t1 = t2.clone();
            }
        }
        let mut t1 = t1;
        mt(&mut t1, &t2);
        t1
    }
}
```