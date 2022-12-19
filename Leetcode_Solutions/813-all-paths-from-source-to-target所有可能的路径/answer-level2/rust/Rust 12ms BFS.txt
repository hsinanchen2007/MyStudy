![image.png](https://pic.leetcode-cn.com/56cb038383a3372f97d07cdf1a58097cfd1b2054b6622891ac20841f5bff71e4-image.png)

```rs
use std::collections::VecDeque;

impl Solution {
    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        // 队列
        let mut queue = VecDeque::new();
        // 初始节点
        queue.push_back(vec![0]);
        // 一个 vector 用于保存结果的
        let mut result = vec![];
        loop {
            if let Some(path) = queue.pop_front() {
                let end = path[path.len()-1];
                if end == (graph.len()-1) as i32 {
                    result.push(path);
                } else {
                    for next in &graph[end as usize] {
                        let mut path1 = path.clone();
                        path1.push(*next);
                        queue.push_back(path1);
                    }
                }
            } else {
                break;
            }
        }
        result
    }
}
```