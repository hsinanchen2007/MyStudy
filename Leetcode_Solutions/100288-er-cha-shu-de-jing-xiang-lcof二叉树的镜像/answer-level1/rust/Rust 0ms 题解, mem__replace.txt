0ms ; 2.1MB

开始时尝试用 `mem::swap`, 结果和 `Rc` 冲突, 上网查了一圈发现可以用 `mem::replace`.
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
    pub fn mirror_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        fn mirror(root: &mut Option<Rc<RefCell<TreeNode>>>) {
            if let Some(node) = root {
                let mut n = node.borrow_mut();
                let lt = std::mem::replace(&mut n.left, None);
                let rt = std::mem::replace(&mut n.right, lt);
                std::mem::replace(&mut n.left, rt);
                mirror(&mut n.left);
                mirror(&mut n.right);
            }
        }
        let mut root = root;
        mirror(&mut root);
        root
    }
}
```