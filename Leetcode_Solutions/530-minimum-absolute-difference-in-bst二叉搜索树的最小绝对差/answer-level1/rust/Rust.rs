### 解题思路
中序遍历，然后求最小值
### 代码

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut nums=Vec::new();
        let mut res=i32::max_value();
        // 二叉树中序遍历
        fn inOrder(root: Option<Rc<RefCell<TreeNode>>>,nums :&mut Vec<i32>){
            if let Some(root)=root {
                inOrder(root.borrow().left.clone(), nums);
                nums.push(root.borrow().val);
                inOrder(root.borrow().right.clone(), nums);
            }
            
        }
        inOrder(root, &mut nums);
        for i in (1..nums.len()){
            if nums[i]-nums[i-1]<res{
                res=nums[i]-nums[i-1]
            }
        }
        res
    }
}


```