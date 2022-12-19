1）双端队列VecDeque，按广搜顺序存结点（level, node）；
2）level计算：孩子的level = 父level + 1；
3）sub_vec 用于存储每一层的node.val；
4) VecDeque pop_front时，当level增加时，表示递进一层，sub_vec push_back到结果ret_vec中，清空sub_vec；

执行用时 :0 ms, 在所有 Rust 提交中击败了100.00%的用户
内存消耗 :2.1 MB, 在所有 Rust 提交中击败了100.00%的用户

```

pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
    use std::collections::VecDeque;

    let mut ret = Vec::new();
    if root.is_none() {
        return ret;
    }
    let mut sub_vec = Vec::new();
    let mut queue = VecDeque::new();
    let mut cur_level = 0;
    queue.push_back((0, root.clone()));
    while !queue.is_empty() {
        if let Some((lev, Some(node))) = queue.pop_front() {
            if lev > cur_level {
                ret.push(sub_vec.clone());
                sub_vec.clear();
                cur_level = lev;
            }
            sub_vec.push(node.borrow().val);
            queue.push_back((lev + 1, node.borrow().left.clone()));
            queue.push_back((lev + 1, node.borrow().right.clone()));
        }
    }

    if !sub_vec.is_empty() {
        ret.push(sub_vec);
    }

    ret
}
```
