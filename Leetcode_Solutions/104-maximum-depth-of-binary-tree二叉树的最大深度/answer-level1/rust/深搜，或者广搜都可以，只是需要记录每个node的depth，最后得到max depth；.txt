1) 深搜，或者广搜都可以，只是需要记录每个node的depth，最后得到max depth；
时间复杂度O(n),空间复杂度O(n);

执行用时 :0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗 :2.7 MB, 在所有 Rust 提交中击败了100.00%的用户

本文给出广搜代码：

```
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        use std::collections::VecDeque;
        if root.is_none(){
            return 0;
        }
        let mut max_depth = 0;
        let mut queue = VecDeque::new();
        queue.push_back((1, root.clone()));
        while !queue.is_empty() {
            if let Some((depth, Some(node))) = queue.pop_front(){
                if depth > max_depth {
                    max_depth = depth;
                }
                queue.push_back((depth + 1, node.borrow().left.clone()));
                queue.push_back((depth + 1, node.borrow().right.clone()));
            }
        }

        max_depth
    }
```
