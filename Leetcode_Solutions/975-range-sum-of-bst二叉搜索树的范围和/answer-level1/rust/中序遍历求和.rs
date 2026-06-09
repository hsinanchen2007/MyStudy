
### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, l: i32, r: i32) -> i32 {
        fn inorder(root: Option<Rc<RefCell<TreeNode>>>,nums :&mut Vec<i32>){
            if let Some(root)=root {
                inorder(root.borrow().left.clone(), nums);
                nums.push(root.borrow().val);
                inorder(root.borrow().right.clone(),nums);
            }
        }
        let mut nums: Vec<i32>=Vec::new();
        inorder(root,&mut nums);
        nums.into_iter().fold(0,|acc,x| {if x>=l&&x<=r{ acc+x }else{ acc }})
    }
}
```