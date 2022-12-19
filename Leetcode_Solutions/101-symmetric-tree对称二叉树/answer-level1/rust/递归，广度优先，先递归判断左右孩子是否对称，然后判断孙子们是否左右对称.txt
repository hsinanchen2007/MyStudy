执行用时 :0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗 :2.1 MB, 在所有 Rust 提交中击败了100.00%的用户

```
pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
    fn is_sym(left: Option<Rc<RefCell<TreeNode>>>, right: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (left, right) {
            (Some(l), Some(r)) => {
                l.borrow().val == r.borrow().val
                    && is_sym(l.borrow().left.clone(), r.borrow().right.clone())
                    && is_sym(l.borrow().right.clone(), r.borrow().left.clone())
            }
            (None, None) => true,
            _ => false,
        }
    }

    if root.is_none() {
        return true;
    }

    let left = root.as_ref().and_then(|v| v.borrow().left.clone());
    let right = root.as_ref().and_then(|v| v.borrow().right.clone());
    is_sym(left, right)
}
```
