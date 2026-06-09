
### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn leaf_similar(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let (mut nums1,mut nums2) = (Vec::new(),Vec::new());
        fn get_leaf(root: Option<Rc<RefCell<TreeNode>>>,nums :&mut Vec<i32>){
            if let Some(root)=root {
                if root.borrow().left== None && root.borrow().right==None{
                    nums.push(root.borrow().val);
                }else{
                    get_leaf(root.borrow().left.clone(),nums);
                    get_leaf(root.borrow().right.clone(),nums);
                }
            }
        }
        get_leaf(root1,&mut nums1);
        get_leaf(root2,&mut nums2);
        if nums1==nums2{
            return true
        }
        false
    }
}
```