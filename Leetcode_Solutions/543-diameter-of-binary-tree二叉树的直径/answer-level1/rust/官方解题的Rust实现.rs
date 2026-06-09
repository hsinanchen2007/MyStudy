### 解题思路
雷同与官方解题，这里只是指出Rust该如何遍历二叉树等`recursivly`结构。
注意如何取RefCell中wrapped TreeNode。 
`Rc<RefCell<TreeNode>>>` ---->  `clone` 创建一个新的`Rc<RefCell<TreeNode>>>` 引用计数+1 在栈上
`Rc<RefCell<TreeNode>>>.borrow()` ----> 智能解引用 相当于 `(*(node.clone())).borrow()` 调用`RefCell.borrow()` 取得 `Ref<TreeNode>`
`Ref<TreeNode>.left.clone()` ----> `Ref<TreeNode>`智能解引用 取得left字段，并调用`clone`获取左子结点
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
    pub fn depth(root: Option<Rc<RefCell<TreeNode>>>,ans: & mut i32) -> i32{
        match root {
            Some(node) => {
                let L = Solution::depth(node.clone().borrow().left.clone(),ans);
                let R = Solution::depth(node.clone().borrow().right.clone(),ans);
                *ans = std::cmp::max(*ans,L+R+1);
                std::cmp::max(L,R) + 1
            },
            None => 0
        }
    }
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans:i32 = 1;
        Solution::depth(root,&mut ans);
        ans - 1
    }
}
```