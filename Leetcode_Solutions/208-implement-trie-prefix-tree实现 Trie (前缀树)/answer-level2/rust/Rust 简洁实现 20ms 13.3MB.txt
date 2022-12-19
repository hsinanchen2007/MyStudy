亮点： 通过 `Default` 简化初始化过程，避免大量模板代码。
```Rust
#[derive(Default)]
pub struct Trie {
    root: Node,
}

#[derive(Default)]
struct Node {
    // Some(Box(next_node)) -> 父节点是子节点的所有者
    children: [Option<Box<Node>>; 26],
    is_word: bool,
}

impl Trie {
    pub fn new() -> Self {
        Self::default()
        // Trie { 
        //     root: Node {
        //         children: [None; 26], -> 直接这样写是不行的，这种写法要求实现了Copy trait
        //         is_word: false,
        //     }
        // }
    }

    pub fn insert(&mut self, word: String) {
        let mut node = &mut self.root;
        for c in word.as_bytes() {
            let idx = (c - b'a') as usize;
            let next = &mut node.children[idx];
            // next.is_some() -> 直接取可变引用
            // next.is_none() -> 插入新的节点，再取其可变引用
            node = next.get_or_insert_with(Box::<Node>::default);
        }
        node.is_word = true;
    }

    pub fn search(&self, word: String) -> bool {
        self.get_node(&word).map_or(false, |w| w.is_word)
        // match self.get_node(&word) {
        //     Some(w) if w.is_word => true,
        //     _ => false
        // }
    }

    pub fn starts_with(&self, prefix: String) -> bool {
        self.get_node(&prefix).is_some()
    }

    /// 取 `s` 对应的节点，如果不存在则返回 `None`
    fn get_node(&self, s: &str) -> Option<&Node> {
        let mut node = &self.root;
        for c in s.as_bytes() {
            let idx = (c - b'a') as usize;
            match &node.children[idx] {
                Some(next) => node = next.as_ref(),
                None => return None,
            }
        }
        Some(node)
    }
}
```