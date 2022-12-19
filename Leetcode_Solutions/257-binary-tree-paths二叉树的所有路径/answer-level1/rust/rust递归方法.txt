想知道一下可以不用递归吗？


```rust
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
        let mut container: Vec<String> = vec![];
        if let Some(r) = root {
            Self::get_all_path(r, &mut vec![], &mut container)
        } else {
            container
        }
    }

    fn get_all_path(
        node: Rc<RefCell<TreeNode>>,
        path: &mut Vec<String>,
        list: &mut Vec<String>,
    ) -> Vec<String> {
        path.push(node.borrow().val.to_string());
        match (node.borrow().left.clone(), node.borrow().right.clone()) {
            (Some(l), Some(r)) => Self::get_all_path(
                l,
                &mut path.clone(),
                &mut Self::get_all_path(r, &mut path.clone(), list),
            ),
            (Some(l), None) => Self::get_all_path(l, &mut path.clone(), list),
            (None, Some(r)) => Self::get_all_path(r, &mut path.clone(), list),
            _ => {
                list.push(path.join("->"));
                list.to_vec()
            }
        }
    }
}
```