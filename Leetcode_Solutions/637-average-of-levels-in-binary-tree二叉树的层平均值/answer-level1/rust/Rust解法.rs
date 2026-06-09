### 解题思路
BFS 队列遍历 求平均值

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
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        // 思路BFS 收集sum和count 并传递到res数组
        let mut res:Vec<f64>=Vec::new();
        let (mut sum,mut count)=(0.0,0.0);
        let mut queue:Vec<Option<Rc<RefCell<TreeNode>>>>=Vec::new();
        queue.push(root);
        while !queue.is_empty() {
            let mut temp:Vec<Option<Rc<RefCell<TreeNode>>>>=Vec::new();
            while !queue.is_empty() {
                if let Some(node) =queue.pop(){
                    let node=node.as_ref().unwrap().borrow();
                    sum+=node.val as f64;
                    count+=1.0;
                    if let Some(left)=node.left.clone(){
                        temp.push(Some(left));
                    }
                    if let Some(right)=node.right.clone(){
                        temp.push(Some(right));
                    }
                };
            }
            res.push(sum/count);
            queue=temp;
            sum=0.0;count=0.0;
        }
        res
    }
}
```