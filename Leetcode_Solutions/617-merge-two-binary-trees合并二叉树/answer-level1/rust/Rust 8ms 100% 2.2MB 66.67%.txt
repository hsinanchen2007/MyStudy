### 解题思路
![image.png](https://pic.leetcode-cn.com/3ae1b2357976f41a843d059b2db9545782e7019d7b8d61c43df104a88684ea85-image.png)


### 代码

```rust
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn merge_trees(
        t1: Option<Rc<RefCell<TreeNode>>>,
        t2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if t1.is_none() {
            return t2;
        }
        if t2.is_none() {
            return t1;
        }

        let b1 = t1.unwrap();
        let b1 = b1.borrow();
        let b2 = t2.unwrap();
        let b2 = b2.borrow();
        Some(Rc::new(RefCell::new(TreeNode {
            val: b1.val + b2.val,
            left: Solution::merge_trees(b1.left.clone(), b2.left.clone()),
            right: Solution::merge_trees(b1.right.clone(), b2.right.clone()),
        })))
    }
}

```