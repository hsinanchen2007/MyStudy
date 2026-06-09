主要思想是使用字典树压缩 string, 且字典树的形式实际上是数组，子节点以 id 形式保存引用，字典树中进行路径压缩。

在序列化反序列化的过程中，使用非 ASCII 码作为分隔符。

![图片.png](https://pic.leetcode-cn.com/c090fcbf989c81036960e266a8d7a815d2a29a5338b93f68941d63b31be5ba7e-%E5%9B%BE%E7%89%87.png)

rust 超过双百分百，当字符串越多效果越好。

```rust
use std::collections::HashMap;
use std::mem::swap;
use std::rc::Rc;
use std::cell::RefCell;
use std::iter::FromIterator;

#[derive(Debug, Clone)]
struct TrieNode {
    id: usize,
    content: Vec<char>,
    children: HashMap<char, usize>,
    term_ids: Vec<usize>,
}

const SP1: &'static str = "临";
const SP2: &'static str = "兵";
const SP3: &'static str = "斗";
const SP4: &'static str = "者";

impl TrieNode {
    pub fn serialize(&self) -> String {
        format!("{}{}{}{}{}{}{}", 
            self.id, 
            SP2,
            self.content.iter().cloned().collect::<String>(),
            SP2,
            self.children
            .iter()
            .map(|(k, v)| format!("{}{}{}", k, SP4, v))
            .collect::<Vec<String>>()
            .join(SP3), 
            SP2,
            self.term_ids.iter().map(|i| i.to_string()).collect::<Vec<String>>().join(SP3)
        )
    }

    pub fn deserialize(s: &str) -> TrieNode {
        let parts = s.split(SP2).collect::<Vec<_>>();
        let id = parts[0].parse::<usize>().unwrap();
        let content = parts[1].chars().collect::<Vec<char>>();
        let children = 
            HashMap::<char, usize>::from_iter(parts[2].split(SP3)
            .filter(|kv| !kv.is_empty())
            .map(|kv| {
                let k_v_arr = kv.split(SP4).collect::<Vec<_>>();
                (k_v_arr[0].chars().next().unwrap(), k_v_arr[1].parse::<usize>().unwrap())
            }));
        let term_ids = parts[3].split(SP3).filter(|s| !s.is_empty())
            .map(|i| i.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        TrieNode {
            id,
            content,
            children,
            term_ids
        }
    }
}

struct TrieTree {
    root: Rc<RefCell<TrieNode>>,
    nodes: Vec<Rc<RefCell<TrieNode>>>,
}

impl TrieTree {
    pub fn new() -> Self {
        let root = 
            Rc::new(
                RefCell::new(
                    TrieNode{
                    id: 0,
                    content: vec![],
                    children: HashMap::new(),
                    term_ids: vec![],
        }));
        TrieTree {
            root: root.clone(),
            nodes: vec![root]
        }
    }

    pub fn gen(&mut self, content: Vec<char>) -> Rc<RefCell<TrieNode>> {
        let node = Rc::new(
            RefCell::new(TrieNode {
            id: self.nodes.len(),
            content,
            children: HashMap::new(),
            term_ids: vec![],
        }));
        self.nodes.push(node.clone());
        node
    }

    pub fn add(&mut self, content: &[char], term_id: usize) {
        self.insert(self.root.clone(), content, term_id);
    }

    pub fn insert(&mut self, node_rc: Rc<RefCell<TrieNode>>, 
        content: &[char], term_id: usize) {
        let mut i = 0;
        let mut node = node_rc.borrow_mut();
        while i<content.len() && i<node.content.len() {
            if content[i]!=node.content[i] {
                break;
            }
            i+=1;
        }
        if i< node.content.len() {
            let new_key: char = node.content[i];
            let new_content = node.content.drain(i..).collect::<Vec<_>>();
            let new_node_rc = self.gen(new_content);
            let mut new_node = new_node_rc.borrow_mut();
            swap(&mut new_node.term_ids, &mut node.term_ids);
            swap(&mut new_node.children, &mut node.children);
            node.children.insert(new_key, new_node.id);
        }
        if i<content.len() {
            let key: char = content[i];
            node.children.entry(key)
                .and_modify(|c| {
                    self.insert( self.nodes[*c].clone(),&content[i..], term_id);
                })
                .or_insert_with(|| {
                    let new_node_rc = 
                        self.gen(content[i..].to_vec());
                    let mut new_node = new_node_rc.borrow_mut();
                    new_node.term_ids.push(term_id);
                    new_node.id
                });
        } else {
            node.term_ids.push(term_id);
        }
    }

    pub fn serialize(&self) -> String {
        self.nodes.iter().map(|n| {
            let node_b = n.borrow();
            node_b.serialize()
        }).collect::<Vec<String>>()
        .join(SP1)
    }

    pub fn deserialize(inputs: &str) -> TrieTree {
        let nodes = inputs.split(SP1)
            .map(|s| Rc::new(RefCell::new(TrieNode::deserialize(s))))
            .collect::<Vec<_>>();
        TrieTree {
            root: nodes[0].clone(),
            nodes
        }
    }

    pub fn retrieve(&self) -> Vec<String> {
        let res_rc = Rc::new(RefCell::new(vec![]));
        {
            self.retrieve_rec(self.nodes[0].clone(), String::from(""), res_rc.clone());
        }
        let mut res = res_rc.borrow_mut();
        res.sort_by_key(|&(_, id)| id);
        res.iter().map(|e| e.0.clone()).collect::<Vec<String>>()
    }

    pub fn retrieve_rec(&self, node_rc: Rc<RefCell<TrieNode>>, 
        mut visited: String,
        res_rc: Rc<RefCell<Vec<(String, usize)>>>) {
        let node = node_rc.borrow();
        visited.extend(node.content.iter());
        {
            let mut res = res_rc.borrow_mut();
            for i in &node.term_ids {
                res.push((visited.clone(), *i));
            }
        }
        for c in node.children.values() {
            let c_node = self.nodes[*c].clone();
            self.retrieve_rec(c_node, visited.clone(), res_rc.clone());
        }
    }
}

 struct Codec {
	
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Self {

        }
    }
	
    fn encode(&self, strs: Vec<String>) -> String {
        let mut trie = TrieTree::new();
        for (i,s) in strs.into_iter().enumerate() {
            let chars = s.chars().collect::<Vec<_>>();
            trie.add(&chars, i);
        }
        trie.serialize()
    }
	
    fn decode(&self, s: String) -> Vec<String> {
        let trie = TrieTree::deserialize(&s);
        trie.retrieve()
    }
}
```