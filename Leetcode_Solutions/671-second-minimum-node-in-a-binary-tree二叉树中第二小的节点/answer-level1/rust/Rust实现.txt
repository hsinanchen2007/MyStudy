### 解题思路
思路来自高赞答案

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
    pub fn find_second_minimum_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(root) = root {
            match(root.borrow().left.clone(),root.borrow().right.clone()){
                (None,None)|(_,None)|(None,_)=>-1,
                (Some(left),Some(right))=>{
                    let (mut l,mut r)=(left.borrow().val,right.borrow().val);
                    if (root.borrow().val==l){
                        l=Solution::find_second_minimum_value(Some(left))
                    }
                    if (root.borrow().val==r){
                        r=Solution::find_second_minimum_value(Some(right))
                    }
                    if l!=-1 && r!=-1 {
                        return l.min(r)
                    }
                    if  l!=-1{
                        return l;
                    }else{
                        return r;
                    }
                }        
            }
        }else{
            -1
        }
    }
}
```