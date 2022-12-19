8 ms; 2.9 MB
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
    pub fn sum_even_grandparent(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn seg(root: &Option<Rc<RefCell<TreeNode>>>, sum: &mut i32, flag_self: bool, flag_child: bool) {
            if let Some(node) = root {
                if flag_self {
                    *sum += node.borrow().val;
                }
                let mut gchild = false;
                if node.borrow().val % 2 == 0 {
                    gchild = true;   
                }
                seg(&node.borrow().left, sum, flag_child, gchild);
                seg(&node.borrow().right, sum, flag_child, gchild);
            }
        }
        let mut sum = 0;
        seg(&root, &mut sum, false, false);
        sum
    }
}
```