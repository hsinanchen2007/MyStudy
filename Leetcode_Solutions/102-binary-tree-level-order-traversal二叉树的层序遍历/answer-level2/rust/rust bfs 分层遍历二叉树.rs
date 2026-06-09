### 解题思路

直接使用bfs，当前队列里的数据就代表这一层的数据，所以循环pop时要从0到当前队列的长度开始


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
    let mut q = VecDeque::new();
    let mut res = vec![];
    if let Some(root_node) = root.as_ref() {
        q.push_back(Rc::clone(root_node));

        while !q.is_empty() {
            let l = q.len();
            let mut t: Vec<i32> = vec![];
            for _i in 0..l {
                let node = q.pop_front().unwrap();
                t.push(node.borrow().val);
                node.borrow().left.as_ref().map(|v| {
                    q.push_back(Rc::clone(v));
                });
                node.borrow().right.as_ref().map(|v| {
                    q.push_back(Rc::clone(v));
                });
            }
            res.push(t);
        }
    }

    res
}
}
```