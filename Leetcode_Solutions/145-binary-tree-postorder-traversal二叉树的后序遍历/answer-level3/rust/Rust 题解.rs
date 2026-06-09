```
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res = Vec::new();
        if let Some(node) = root {
            res.append(&mut Solution::postorder_traversal(node.borrow().left.clone()));
            res.append(&mut Solution::postorder_traversal(node.borrow().right.clone()));
            res.push(node.borrow().val);
        }
        res
    }
}
```

