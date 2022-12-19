### 解题思路
用队列、广度优先遍历
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
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec!();
        if root.is_none() {
            return result;
        }
        let mut d = VecDeque::new(); //队列
        let root = root.unwrap();
        d.push_back(root); //根节点入队列
        while !d.is_empty() {
            let mut v: Vec<i32> = vec!();
            let size = d.len(); //每一层的节点数
            for _ in 0..size {
                let node = d.pop_front().unwrap();
                let val = node.borrow().val; //获取值
                v.push(val);

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
        }
        result
    }
}
```