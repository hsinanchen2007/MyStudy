### 解题思路
参考了大佬们的思路
//每次新增的数字都大于之前的数字，所以新增的数字位置只能是根节点或者根节点的右孩子，右孩子的右孩子，右孩子的右孩子的右孩子等等
//总之一定是右边。其次，新数字所在位置的原来的子树，移为新插入的节点的左孩子即可

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
    pub fn generate_trees(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let mut result: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
        if n == 0 {
            return result;
        }
        //初始化
        result.push(Some(Rc::new(RefCell::new(TreeNode::new(1)))));

        for i in 2..=n {
            let mut curr_trees: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
            while !result.is_empty() {
                let root = result.pop().unwrap();
                if root.is_none() {
                    break;
                }
                //创建待插入的节点
                let insert = Rc::new(RefCell::new(TreeNode::new(i)));
                //复制一份根节点，避免相互引用
                let root_copy = tree_copy(root.as_ref()).unwrap();
                //新节点作为根节点插入
                insert.borrow_mut().left = Some(Rc::clone(&root_copy));
                curr_trees.push(Some(Rc::clone(&insert)));
                //插入到右孩子，右孩子的右孩子...最多找 n 次孩子
                for j in 0..=n {
                    //复制一份根节点，避免相互引用
                    let root_copy = tree_copy(root.as_ref()).unwrap();
                    //开始找右孩子（j=1时找到根节点的第一个右孩子，j=2找到根节点的右孩子的右孩子，以此类推）
                    let mut right = Some(Rc::clone(&root_copy));
                    for _ in 0..j {
                        //还没找完j步，右孩子就为空则直接结束
                        if right.is_none() {
                            break;
                        }
                        let curr_node = right.unwrap();
                        let tmp = curr_node.borrow_mut().right.take();
                        match tmp {
                            None => right = None,
                            Some(node) => {
                                curr_node.borrow_mut().right = Some(Rc::clone(&node));
                                right = Some(Rc::clone(&node));
                            }
                        }
                    }
                    //到达 null 提前结束（不能给null插入新节点作为右孩子）
                    if right.is_none() {
                        break;
                    }
                    //在此位置的右节点插入新的节点，并把此位置原来的右孩子作为新节点的左孩子
                    let right = right.unwrap();
                    let temp = right.borrow_mut().right.take();
                    let insert = Rc::new(RefCell::new(TreeNode::new(i)));
                    right.borrow_mut().right = Some(Rc::clone(&insert));
                    match temp {
                        None => (),
                        Some(node) => {
                            insert.borrow_mut().left = Some(Rc::clone(&node));
                        }
                    }
                    //加入到结果中
                    curr_trees.push(Some(root_copy));
                }
            }
            //用此结果做为下一循环的根数据
            result = curr_trees;
        }
        result
    }
}

//复制树
pub fn tree_copy(root: Option<&Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    if root.is_none() {
        return None;
    }
    let root = root.unwrap();
    let new_node = Rc::new(RefCell::new(TreeNode::new(root.borrow().val)));
    new_node.borrow_mut().left = tree_copy(root.borrow_mut().left.as_ref());
    new_node.borrow_mut().right = tree_copy(root.borrow_mut().right.as_ref());
    return Some(new_node);
}
```