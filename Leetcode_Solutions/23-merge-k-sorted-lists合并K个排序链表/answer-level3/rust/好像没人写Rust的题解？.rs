```rust
use std::collections::{BTreeSet, BTreeMap, HashSet, HashMap, BinaryHeap};
use std::{i32, i64, u32, u64};
use std::cmp::{Reverse, Ordering};

struct KVPair {
    value: i32,
    from_list: usize
}

impl PartialEq for KVPair {
    fn eq(&self, other: &Self) -> bool {
        self.value == other.value
    }

    fn ne(&self, other: &Self) -> bool {
        self.value != other.value
    }
}

impl PartialOrd for KVPair {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.value.cmp(&other.value))
    }

    fn lt(&self, other: &Self) -> bool {
        self.value < other.value
    }

    fn le(&self, other: &Self) -> bool {
        self.value <= other.value
    }

    fn gt(&self, other: &Self) -> bool {
        self.value > other.value
    }

    fn ge(&self, other: &Self) -> bool {
        self.value >= other.value
    }
}

impl Eq for KVPair {}

impl Ord for KVPair {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl KVPair {
    pub fn new(value: i32, from_list: usize) -> Self {
        KVPair { value, from_list }
    }
}

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut heap = BinaryHeap::new();
        let mut heads = Vec::new();
        for list in lists.iter() {
            heads.push(list);
        }

        for (i, head) in heads.iter_mut().enumerate() {
            if let Some(node) = head {
                heap.push(Reverse(KVPair::new(node.val, i)));
                *head = &node.next;
            }
        }

        let mut merged_list: Option<Box<ListNode>> = None;
        let mut list_tail = &mut merged_list;

        while let Some(kv_pair) = heap.pop() {
            let new_node = Box::new(ListNode::new(kv_pair.0.value));
            if let Some(node) = heads[kv_pair.0.from_list] {
                heap.push(Reverse(KVPair::new(node.val, kv_pair.0.from_list)));
                heads[kv_pair.0.from_list] = &node.next;
            }
            if let Some(tail) = list_tail {
                tail.next = Some(new_node);
                list_tail = &mut tail.next;
            } else {
                *list_tail = Some(new_node);
            }
        }

        merged_list
    }
}
```
