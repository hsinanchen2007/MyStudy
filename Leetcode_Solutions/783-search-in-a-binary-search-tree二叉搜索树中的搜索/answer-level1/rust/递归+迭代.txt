
### 代码
+ 递归
```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(root) = root {
            if root.borrow().val ==val{
                Some(root)
            }else if root.borrow().val>val{
                Solution::search_bst(root.borrow().left.clone(),val)
            }else{
                Solution::search_bst(root.borrow().right.clone(),val)
            }
        }else{
            None
        }
    }
}

```
+ 迭代
```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        let mut root =root;
        while root!=None && root.clone().unwrap().borrow().val !=val{
            if root.clone().unwrap().borrow().val>val{
                root=root.clone().unwrap().borrow().left.clone();
            }else{
                root=root.clone().unwrap().borrow().right.clone();
            }
        }
        root
    }
}
```