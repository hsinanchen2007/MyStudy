### 解题思路
![图片.png](https://pic.leetcode-cn.com/73f38ef2ff056f5ffc83bf3c6f307b6c97d6c01b11ca69408eb9dfdbcd6036e8-%E5%9B%BE%E7%89%87.png)


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
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        if root.is_none() {
            return vec![];
        }
        let mut q = VecDeque::new();
        let mut zigzag = false;
        let mut res = Vec::new();
        q.push_back(root);
        while !q.is_empty() {
            let mut v: Vec<i32> = Vec::new();
            let mut size = q.len();
            while size > 0 {
                if zigzag {
                    let r = q.pop_front().unwrap().unwrap();
                    let b = r.borrow();
                    if !b.right.is_none() {
                        q.push_back(b.right.clone());
                    }
                    if !b.left.is_none() {
                        q.push_back(b.left.clone());
                    }
                    v.push(b.val);
                } else {
                    let r = q.pop_back().unwrap().unwrap();
                    let b = r.borrow();
                    if !b.left.is_none() {
                        q.push_front(b.left.clone());
                    }
                    if !b.right.is_none() {
                        q.push_front(b.right.clone());
                    }
                    v.push(b.val);
                }
                size -= 1;
            }
            zigzag = !zigzag;
            res.push(v);
        }
        res
    }
}
```