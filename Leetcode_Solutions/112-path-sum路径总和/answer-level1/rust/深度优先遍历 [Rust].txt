### 解题思路

递归逐层减`sum`，到叶子节点时判断当前`sum`是否为0

### 代码

```rust

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> bool {
        if root.is_none() { false } else {
            Solution::find(root.as_ref(), sum)
        }
    }
    fn find(root: Option<&Rc<RefCell<TreeNode>>>, sum: i32) -> bool {
        if let Some(c) = root {
            let rest = sum - c.borrow().val;
            if c.borrow().left.is_none() && c.borrow().right.is_none() {
                rest == 0
            } else {
                Solution::find(c.borrow().left.as_ref(), rest) ||
                    Solution::find(c.borrow().right.as_ref(), rest)
            }
        } else {
            false
        }
    }
}
```