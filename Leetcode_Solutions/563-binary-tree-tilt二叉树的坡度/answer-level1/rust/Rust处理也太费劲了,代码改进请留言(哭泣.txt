### 解题思路
自下向上，递归的同时累加结点的val值

### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn find_tilt(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = 0i32;
        fn helper(root: Option<Rc<RefCell<TreeNode>>>,res :&mut i32){
            if let Some(root) = root {
                let mut root=root.borrow_mut(); 
                match (root.left.clone(),root.right.clone()){
                    (None,None)=>(),
                    (None,Some(right))=>{
                        helper(Some(right.clone()),res);
                        root.val+=right.borrow().val;    
                        *res+=right.borrow().val.abs();
                    },
                    (Some(left),None)=>{
                        helper(Some(left.clone()),res);
                        root.val+=left.borrow().val;    
                        *res+=left.borrow().val.abs();
                    },
                    (Some(left),Some(right))=>{
                        helper(Some(left.clone()),res);
                        helper(Some(right.clone()),res);
                        root.val+=left.borrow().val+right.borrow().val;    
                        *res+=(left.borrow().val-right.borrow().val).abs();
                    }
                }
            }
        }
        helper(root,&mut res);
        res
    }
}
```