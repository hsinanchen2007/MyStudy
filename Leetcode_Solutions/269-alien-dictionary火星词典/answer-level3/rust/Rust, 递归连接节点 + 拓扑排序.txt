将原始字符串数组转换为字符二维数组，依次进行：

- 生成空节点
- 递归的连接节点
    - 单次过程中的空白只能排在开始，否则非法
    - 单次过程的前驱字符相同
- 拓扑排序，若无变化时还有剩余则非法

![图片.png](https://pic.leetcode-cn.com/8a2217aff7da0adc7cd023ba2b90f1efc2991633bd552df3349b5d03c52c2dd1-%E5%9B%BE%E7%89%87.png)

均超过 100%，可能是没有人用 rust 的原因？


```rust
use std::collections::HashMap;
use std::collections::HashSet;
use std::iter::FromIterator;

#[derive(Clone, Debug)]
struct GraphNode {
    ins:  HashSet<char>,
    outs: HashSet<char>,
}

impl GraphNode {
    fn new() -> GraphNode {
        GraphNode {
            ins: HashSet::new(),
            outs: HashSet::new(),
        }
    } 
}

impl Solution {
    fn link_graph(
        words: &Vec<Vec<char>>, 
        c: usize, 
        rs: usize, 
        re: usize,
        nodes: &mut HashMap<char, GraphNode>
    ) -> bool {
        if rs+1>=re {
            return true;
        }
        let mut orders: Vec<(char, usize, usize)> = vec![];
        let mut last_empty = rs;
        for i in rs..re {
            if words[i].len() > c {
                let ch = words[i][c];
                if orders.is_empty() || orders[orders.len() - 1].0!=ch {
                    orders.push((ch, i, i+1));
                } else {
                    let end = orders.len() - 1;
                    orders[end].2 = i+1;
                }
            } else {
                if i!=last_empty {
                    return false;
                } else {
                    last_empty+=1;
                }
            }
        }
        for i in 1..orders.len() {
            let prev = &orders[i-1].0;
            let curr = &orders[i].0;
            nodes.get_mut(curr).unwrap().ins.insert(*prev);
            nodes.get_mut(prev).unwrap().outs.insert(*curr);
        }
        for o in orders {
            if !Solution::link_graph(words, c+1, o.1, o.2, nodes) {
                return false;
            }
        }
        true
    }

    pub fn alien_order(words: Vec<String>) -> String {
        let words = words
            .iter()
            .map(|s| s.chars().collect::<Vec<char>>())
            .collect::<Vec<Vec<char>>>();
        let mut nodes: HashMap<char, GraphNode> = HashMap::from_iter(
            HashSet::<&char>::from_iter(
                words
                    .iter()
                    .flatten())
                .into_iter()
                .map(|c| (*c, GraphNode::new())
            )
        );
        if !Solution::link_graph(&words, 0, 0, words.len(), &mut nodes) {
            return String::new();
        }
        let mut res = String::new();
        loop {
            let mut changed = false;
            let zero_in_nodes = 
                nodes
                    .iter()
                    .filter(|(_,n)| n.ins.is_empty())
                    .map(|(k,_)| *k)
                    .collect::<Vec<char>>();
            for n in zero_in_nodes {
                let outs = nodes.get(&n).unwrap().outs.clone();
                for o in outs {
                    nodes.get_mut(&o).unwrap().ins.remove(&n);
                }
                nodes.remove(&n);
                res.push(n);
                changed = true;
            }
            if !changed {
                break;
            }
        }
        if !nodes.is_empty() {
            String::new()
        } else {
            res
        }
    }
}
```