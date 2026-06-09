### 解题思路

和[第102题](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/) 是差不多的思路，区别在于每往下走一层要变换一次顺序，最简单的办法还是按照102广度搜索的方式自左向右搜索，如果要变方向那在把本层的结果添加到总结果集里的时候判断方向，每往下走一层改一次方向

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
use std::collections::VecDeque;

impl Solution {
pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
    let mut q = VecDeque::new();
    let mut res = vec![];
    let mut is_right_to_left = false; // true: 右->左， false： 左->右
    if let Some(root_node) = root.as_ref() {
        q.push_back(Rc::clone(root_node));

        while !q.is_empty() {
            let l = q.len();
            let mut t: Vec<i32> = vec![]; // 临时变量，包含本层的结点的值
            for _i in 0..l { // 广度搜索的方向没变还是自左往右
                let node = q.pop_front().unwrap();
                t.push(node.borrow().val);

                node.borrow().left.as_ref().map(|v| {
                    q.push_back(Rc::clone(v));
                });
                node.borrow().right.as_ref().map(|v| {
                    q.push_back(Rc::clone(v));
                });
            }
            
            if !is_right_to_left {
                res.push(t);
            } else { // 如果本层的结果要从右往左展示，那就要反一下
                res.push(t.into_iter().rev().collect::<Vec<i32>>());
            }
            
            is_right_to_left = !is_right_to_left;
        }
    }

    res
}
}
```