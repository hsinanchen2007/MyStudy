### 解题思路
最简单思路 中序遍历得出数组
双指针遍历
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
    pub fn find_target(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        // 思路：中序遍历得出Vec 然后再遍历数组
        let mut nums =Vec::new();
        // 中序遍历
        fn inorder(root: Option<Rc<RefCell<TreeNode>>>,nums: &mut Vec<i32>){
            if let Some(root) = root {
                inorder(root.borrow().left.clone(), nums);
                nums.push(root.borrow().val as i32);
                inorder(root.borrow().right.clone(), nums);
            }
        }
        inorder(root, &mut nums);
        for i in 0..nums.len(){
            for j in i+1..nums.len(){
                if nums[i]+nums[j]==k {
                    return true;
                }
            }
        }
        false
    }
}
```