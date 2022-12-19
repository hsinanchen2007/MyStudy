### 解题思路
此处撰写解题思路

### 代码

```rust
use std::cmp::Ordering;
use std::collections::BTreeSet;
use std::collections::HashMap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct Node{
    cnt:i32,
    time:i32,
    key:i32,
    value:i32
}
impl Ord for Node {
    fn cmp(&self, other: &Node) -> Ordering {
         self.cnt.cmp(&other.cnt)
                .then_with(|| self.time.cmp(&other.time))
    }
}
impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Node) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct LFUCache {
    capacity:i32,
    time:i32,
    key_table:HashMap<i32,Node>,
    S:BTreeSet<Node>
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LFUCache {

    fn new(capacity: i32) -> Self {
        LFUCache{
            capacity:capacity,
            time:0,
            key_table:HashMap::new(),
            S:BTreeSet::new()
        }
    }
    
    fn get(&mut self, key: i32) -> i32 {
        if self.capacity == 0 {
            return -1;
        }
        if !self.key_table.contains_key(&key) {
            return -1;
        }
        let mut cache:Node = self.key_table[&key];
        //
        self.S.remove(&cache);
        //
        cache.cnt += 1;
        self.time += 1;
        cache.time = self.time;
        //
        self.S.insert(cache);
        self.key_table.insert(key,cache);
        //
        cache.value
    }
    
    fn put(&mut self, key: i32, value: i32) {
        if self.capacity == 0 {
            return;
        }
        if !self.key_table.contains_key(&key) {
            if self.key_table.len() == self.capacity as usize{
                let tc = self.S.iter().next().unwrap().clone();
                self.key_table.remove(&tc.key);
                self.S.remove(&tc);   
            }
            self.time += 1;
            let cache = Node{cnt:1,time:self.time, key:key, value:value};
            self.key_table.insert(key,cache);
            self.S.insert(cache);
        }
        else{
            let mut cache = self.key_table[&key];
            self.S.remove(&cache);
            cache.cnt += 1;
            self.time += 1;
            cache.time = self.time;
            cache.value = value;
            self.S.insert(cache);
            self.key_table.insert(key,cache);
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * let obj = LFUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */
```