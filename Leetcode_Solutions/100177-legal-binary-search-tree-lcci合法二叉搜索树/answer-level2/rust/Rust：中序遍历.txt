中序遍历判断其是否严格递增即可。

```
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
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(root) = root {
            let mut stack :Vec<Rc<RefCell<TreeNode>>> = vec![];
            let mut cur = Option::Some(root.clone());
            let mut prev :Option<i32> = Option::None;
            while !stack.is_empty() || cur.is_some() {
                while cur.is_some() {
                    let cur_node = cur.unwrap();
                    stack.push(cur_node.clone());
                    if cur_node.borrow().left.is_some() {
                        cur = cur_node.borrow().left.clone();
                    } else {
                        break;
                    }
                }


                let cur_node = stack.pop().unwrap();
                match prev {
                    Some(prevNum) => {
                        if prevNum >= cur_node.borrow().val {
                            return false;
                        }

                        prev = Option::Some(cur_node.borrow().val);
                    }
                    None => prev = Option::Some(cur_node.borrow().val)
                }

                cur = cur_node.borrow().right.clone();
            }
            return true;
        }
        return true;
    }
}
```
