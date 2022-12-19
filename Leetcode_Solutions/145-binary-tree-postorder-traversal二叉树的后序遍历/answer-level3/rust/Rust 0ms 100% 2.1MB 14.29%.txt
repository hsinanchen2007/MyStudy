### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/1ac236b6f45770738530ed6e007ee77d1c79096edfd9977e543cd4187481a34f-image.png)

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
use std::rc::Rc;
impl Solution {
    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();
        Solution::travel(&root, &mut res);
        res
    }

    pub fn travel(root: &Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
        if root.is_none() {
            return;
        }

        if let Some(r) = root {
            let b = r.borrow();
            if !b.left.is_none() {
                Solution::travel(&b.left, v);
            }

            if !b.right.is_none() {
                Solution::travel(&b.right, v);
            }

            v.push(b.val);
        }
    }
}
```