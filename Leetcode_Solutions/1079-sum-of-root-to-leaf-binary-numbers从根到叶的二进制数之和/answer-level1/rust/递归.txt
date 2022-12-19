
### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn getSum(root: Option<Rc<RefCell<TreeNode>>>,mut num: i32,res:&mut i32){
            if let Some(root)=root {
                num = (num<<1)+root.borrow().val;
                if root.borrow().left ==None && root.borrow().right ==None{
                    *res+=num;
                }else{
                    getSum(root.borrow().left.clone(),num,res);
                    getSum(root.borrow().right.clone(), num,res);
                }
            }
        }
        let (mut num,mut res)=(0,0);
        getSum(root,num,&mut res);
        res
    }
}
```