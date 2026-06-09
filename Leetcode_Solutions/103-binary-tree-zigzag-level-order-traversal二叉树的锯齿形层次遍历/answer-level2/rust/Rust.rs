### 解题思路
此处撰写解题思路

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
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec!();
        if root.is_none() {
            return result;
        }
        let mut d = VecDeque::new();
        let root = root.unwrap();
        let mut rev = true; //反转标志
        d.push_back(root);
        while !d.is_empty() {
            let mut v: Vec<i32> = vec!();
            let size = d.len();
            for _ in 0..size {
                let node = d.pop_front().unwrap();
                let val = node.borrow().val; //获取值
                if rev {
                    v.push(val);
                } else {
                    v.insert(0, val); //倒序
                }
                //子节点入队列
                if let Some(left) = node.borrow_mut().left.take() {
                    d.push_back(left)
                };
                if let Some(right) = node.borrow_mut().right.take() {
                    d.push_back(right)
                };
            }
            if v.len() > 0 {
                result.push(v);
            }
            rev = !rev;
        }
        result
    }
}
```