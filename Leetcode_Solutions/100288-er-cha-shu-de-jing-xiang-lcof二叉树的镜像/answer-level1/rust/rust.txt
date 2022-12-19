### 解题思路
1、非递归：层级遍历，逐层替换
2、递归
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
use std::collections::VecDeque;
impl Solution {
    //非递归
    pub fn mirror_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }
        //队列
        let mut d = VecDeque::new();
        let root = root.unwrap();
        d.push_back(Rc::clone(&root));
        while d.len() != 0 {
            for _ in 0..d.len() {
                let curr = d.pop_front().unwrap();
                let l = curr.borrow_mut().left.take();
                let r = curr.borrow_mut().right.take();
                //交互左右节点
                curr.borrow_mut().left = r;
                curr.borrow_mut().right = l;
                //下一层级节点入队列
                if curr.borrow_mut().left.is_some() {
                    d.push_back(Rc::clone(&curr.borrow_mut().left.as_ref().unwrap()));
                }
                if curr.borrow_mut().right.is_some() {
                    d.push_back(Rc::clone(&curr.borrow_mut().right.as_ref().unwrap()));
                }
            }
        }
        Some(root)
    }

    //递归
    pub fn mirror_tree_ii(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }
        let root = root.unwrap();
        let l = Self::mirror_tree_ii(root.borrow_mut().left.take());
        let r = Self::mirror_tree_ii(root.borrow_mut().right.take());
        root.borrow_mut().left = r;
        root.borrow_mut().right = l;
        Some(root)
    }
}
```