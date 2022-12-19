BFS和DFS实际上都可以，这里用Rust简单实现BFS。

```
use std::collections::HashSet;
impl Solution {
    pub fn find_whether_exists_path(n: i32, graph: Vec<Vec<i32>>, start: i32, target: i32) -> bool {

        let mut graph_mapped :Vec<HashSet<i32>> = vec![HashSet::new(); n as usize];
        graph.iter().for_each(|edge| {
            graph_mapped[edge[0] as usize].insert(edge[1]); 
        });

        let mut visited = vec![false; n as usize];
        let mut queue :Vec<i32> = vec![];
        visited[start as usize] = true;
        queue.push(start);

        while !queue.is_empty() {
            let from = queue.remove(0);
            for to in graph_mapped[from as usize].iter() {
                if !visited[*to as usize] {
                    visited[*to as usize] = true;
                    queue.push(*to);
                    if *to == target {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}
```
