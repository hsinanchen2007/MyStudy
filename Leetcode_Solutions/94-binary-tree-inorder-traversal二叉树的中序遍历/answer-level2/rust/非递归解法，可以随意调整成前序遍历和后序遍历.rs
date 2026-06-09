```rust
impl Solution {
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        enum Visited {
            Yes,
            No
        }
        let mut stack:Vec<(Option<Rc<RefCell<TreeNode>>>, Visited)> = vec![];
        let mut res = vec![];
        stack.push((root, Visited::No));
        loop {
            if stack.len() == 0{
                break;
            }
            let st = stack.pop().unwrap();
            if let Some(node) = st.0.clone() {
                if let Visited::No = st.1 {
                    // 此处从下到上是中序遍历的顺序
                    // 前序遍历把中间那条放最后
                    // 后续遍历把中间那条放最前
                    stack.push((node.borrow().right.clone(), Visited::No));
                    stack.push((st.0.clone(), Visited::Yes));
                    stack.push((node.borrow().left.clone(), Visited::No));
                } else {
                    res.push(node.borrow().val);
                }
            }
        }
        res
    }
}
```
