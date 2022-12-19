
### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn trim_bst(root: Option<Rc<RefCell<TreeNode>>>, l: i32, r: i32) -> Option<Rc<RefCell<TreeNode>>> {
        fn trim(root: Option<Rc<RefCell<TreeNode>>>,l: i32, r: i32) ->Option<Rc<RefCell<TreeNode>>>{
            if let Some(root) =root.clone(){
                let mut root  = root.borrow_mut();
                if root.val > r {
                    return trim(root.left.clone(),l ,r);
                }else if root.val < l{
                    return trim(root.right.clone(),l ,r);
                }else{
                    root.left=trim(root.left.clone(),l ,r);
                    root.right=trim(root.right.clone(),l ,r);
                }
            }
            root
        };
        trim(root,l ,r)
    }
}
```