

### 代码

```rust
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let length = nums.len();
        if nums.len()==0{
            return None
        }
        if nums.len()==1{
            return Some(Rc::new(RefCell::new(TreeNode::new(nums[0]))))
        }
        let mut middle = length/2;
        let mut head =Some(Rc::new(RefCell::new(TreeNode::new(nums[middle]))));
        head.as_ref().unwrap().borrow_mut().left=Solution::sorted_array_to_bst(nums[..middle].to_vec());
        head.as_ref().unwrap().borrow_mut().right=Solution::sorted_array_to_bst(nums[middle+1..].to_vec());
        head
    }
}
```