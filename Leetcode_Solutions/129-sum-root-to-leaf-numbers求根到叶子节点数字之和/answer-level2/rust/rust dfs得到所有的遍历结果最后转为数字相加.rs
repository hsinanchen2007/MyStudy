```rust
pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let mut res = vec![];
    dfs(root.as_ref(), &mut res, vec![]);

    let mut ans = 0;
    for row in res {
        let t: String = row
            .iter()
            .map(|v| v.to_string())
            .collect::<Vec<String>>()
            .join("");
        ans += t.parse::<i32>().unwrap();
    }
    ans
}

fn dfs(root: Option<&Rc<RefCell<TreeNode>>>, res: &mut Vec<Vec<i32>>, mut cur: Vec<i32>) {
    if let Some(root_node) = root {
        cur.push(root_node.borrow().val);
        if root_node.borrow().left.is_none() && root_node.borrow().right.is_none() {
            res.push(cur);
            return;
        } else {
            dfs(root_node.borrow().left.as_ref(), res, cur.clone());
            dfs(root_node.borrow().right.as_ref(), res, cur);
        }
    }
}
```

选定根节点向下递归查找，当查到叶子结点的时候这条回溯路径终止。如果有左右结点则要递归搜索左右分支