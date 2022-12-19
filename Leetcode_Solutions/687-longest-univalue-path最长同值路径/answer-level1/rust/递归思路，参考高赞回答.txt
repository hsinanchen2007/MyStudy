### 解题思路
使用全局变量返回最后的答案，每次递归返回左子树或右子树同根节点的最大路径

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
    pub fn longest_univalue_path(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn helper(root: Option<Rc<RefCell<TreeNode>>>,res: &mut i32)->i32{
            if let Some(root) = root {
                // let (mut left,mut right)=(root.borrow().left.as_ref().unwrap().borrow().val,root.borrow().right.as_ref().unwrap().borrow().val);
                let (mut left,mut right)=(helper(root.borrow().left.clone(),res),helper(root.borrow().right.clone(),res));
                if let Some(l) = root.borrow().left.clone() {
                    if l.borrow().val == root.borrow().val{
                        left+=1
                    }else{
                        left=0
                    }
                }else{
                    left=0
                }
                if let Some(r) = root.borrow().right.clone() {
                    if r.borrow().val == root.borrow().val{
                        right+=1
                    }else{
                        right=0
                    }
                }else{
                    right=0
                }
                *res=(*res).max(left+right);
                left.max(right)
            }else{
                0
            }
        }
        let mut res=0i32;
        helper(root, &mut res);
        res
    }
}

```