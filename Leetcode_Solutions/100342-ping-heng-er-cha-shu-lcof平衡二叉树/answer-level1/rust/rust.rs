### 解题思路
递归比较左右子树深度

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
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        check_balanced(root.as_ref())
    }
}

//是否平衡二叉树
 fn check_balanced(root: Option<&Rc<RefCell<TreeNode>>>) -> bool {
    if root.is_none() {
        return true;
    }
    let node = root.unwrap();
    let left = tree_dept(node.borrow().left.as_ref());  //左子树深度
    let right = tree_dept(node.borrow().right.as_ref()); //右子树深度
    if (left-right).abs() > 1 { //相差超过1 则不平衡
        return false;
    }
    return check_balanced(node.borrow().left.as_ref()) && check_balanced(node.borrow().right.as_ref());

 }
//获取树的深度
fn tree_dept(root: Option<&Rc<RefCell<TreeNode>>>) -> i32 {
    if root.is_none() {
        return 0;
    }
    let node = root.unwrap();
    let left = tree_dept(node.borrow().left.as_ref());
    let right = tree_dept(node.borrow().right.as_ref());
    return 1 + left.max(right);
}

```