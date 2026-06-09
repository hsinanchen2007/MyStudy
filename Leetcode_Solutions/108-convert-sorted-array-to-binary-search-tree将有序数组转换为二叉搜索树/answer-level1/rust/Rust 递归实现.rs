### 解题思路

![image.png](https://pic.leetcode-cn.com/c17801cd88c9f74c65243a871fad9b81b2c1ed39dbfe8832ca7074b9da4b09b3-image.png)

可以使用递归的方法解决。一个有序数组可以和一个平衡二叉树对应，数组中间的值作为根元素，左半部分为根元素左叶，右半部分为根元素右叶。
用伪代码(类似Rust但不考虑borrow checker)表示为

```
// 此函数左闭右开，初始时
// start = 0, end = array.len()
arrary_to_bst(array, start, end) -> Option<TreeNode> {
    if start >= end {
        return None;
    } else {
        let mid = (start + end) / 2;
        let node = TreeNode::new(array[mid]);
        // 递归构建左叶，注意把 mid 作为 end
        node.left = array_to_bst(array, start, mid);
        // 递归构建右叶
        node.right = array_to_bst(array, mid + 1, end);
        Some(node)
    }
}
```

由于 Rust 自身的 borrow checker 需要使用 Rc 来共享所有权，使用 RefCell 来实现内部可变性，所以代码会显得稍微复杂点。
不熟悉的可以参考 Rust 的文档。

[Rc](https://doc.rust-lang.org/std/rc/struct.Rc.html)
[RefCell](https://doc.rust-lang.org/std/cell/struct.RefCell.html)



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
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
       if nums.is_empty() {
            None
        } else {
            help(&nums, 0, nums.len())
        }
    }
}

fn help(nums: &Vec<i32>, start: usize, end: usize) -> Option<Rc<RefCell<TreeNode>>> {
    if start >= end {
        None
    } else {
        let mid = (start + end) / 2;
        let node = Rc::new(RefCell::new(TreeNode::new(nums[mid])));
        node.borrow_mut().left = help(nums, start, mid);
        node.borrow_mut().right = help(nums, mid + 1, end);
        Some(node)
    }
}
```