### 解题思路
此处撰写解题思路

### 代码

```rust
#[derive(Default)]
struct TrieNode{
    val: char,
    children: [Option<Box<TrieNode>>;26]
}
#[derive(Default)]
pub struct Trie{
    root: TrieNode
}
impl Trie{
    pub fn new() -> Self {
        Self::default()
    }
    pub fn insert(&mut self, word:String) -> i32 {
        let mut isNew=false;
        let mut curNode = &mut self.root;
        for c in word.chars().rev(){
            let ic = c as u8 - 'a' as u8;
            let next=&mut curNode.children[ic as usize];
            if next.is_none(){
                isNew=true;
            }
            curNode=next.get_or_insert_with(Box::<TrieNode>::default);            
        }
        match isNew{
            true => word.len() as i32 + 1,
            false => 0
        }
    }
}
impl Solution {
    pub fn minimum_length_encoding(words: Vec<String>) -> i32 {
        let mut length = 0;
        let mut trie = Trie::new();
        let mut words = words;
        words.sort_by(|a,b| b.len().cmp(&a.len()));
        for s in words{
            length += trie.insert(s);
        }
        length
    }
}


```