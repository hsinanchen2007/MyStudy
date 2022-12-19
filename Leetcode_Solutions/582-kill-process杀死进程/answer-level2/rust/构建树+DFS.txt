rust 24ms
基本思想很简单，根据pid -> ppid构建一颗树`HashMap<ppid, Vec<pid>>`。然后从kill节点开始dfs，记录所有子节点就行了。总体复杂度就是O(n)
```rust
use std::collections::HashMap;

impl Solution {
    pub fn kill_process(pid: Vec<i32>, ppid: Vec<i32>, kill: i32) -> Vec<i32> {
        let mut child = HashMap::new();
        for (&pid, &ppid) in pid.iter().zip(ppid.iter()) {
            child.entry(ppid).or_insert(vec![]).push(pid);
        }
        let mut ans = vec![];
        Self::dfs(kill, &child, &mut ans);
        ans
    }
    fn dfs(cur: i32, child: &HashMap<i32, Vec<i32>>, ans: &mut Vec<i32>) {
        ans.push(cur);
        if let Some(arr) = child.get(&cur) {
            for &pid in arr {
                Self::dfs(pid, child, ans);
            }
        }
    }
}
```