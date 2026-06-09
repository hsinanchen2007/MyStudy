

### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn depth(root: Option<Rc<RefCell<TreeNode>>>)-> i32{
            if let Some(root) = root {
                let left = depth(root.borrow().left.clone()); 
                let right = depth(root.borrow().right.clone());
                left.max(right)+1 
            }else{
                0
            }
        }

        if let Some(root) = root {
            if (depth(root.borrow().left.clone())-depth(root.borrow().right.clone())).abs()>1{
                false
            }else{
                Solution::is_balanced(root.borrow().left.clone())&&Solution::is_balanced(root.borrow().right.clone())
            }
        }else{
            true
        }
        
    }
}

```