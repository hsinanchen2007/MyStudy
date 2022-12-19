Rust的```Option<Box<ListNode>>```型链表实际上是一种栈，因此只能通过较为低效的双栈操作来实现对任意节点的操作
当然，在unsafe模式下可以利用原始指针达到与C相同的效果

```rust
#[derive(Clone)]
struct ListNode {
    val: i32,
    next: Option<Box<ListNode>>
}

fn addNode(node: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
    Some(Box::new(ListNode {val, next: node}))
}

fn reverse(node: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut node = node;
    let mut res = None;
    while let Some(t) = node {
        res = Some(Box::new(ListNode {val: t.val, next: res}));
        node = t.next;
    }
    res
}

struct MyLinkedList {
    head: Option<Box<ListNode>>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {

    /** Initialize your data structure here. */
    fn new() -> Self {
        MyLinkedList {head: None}
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    fn get(&self, index: i32) -> i32 {
        let len = self.len();
        if index < 0 || index >= len {return -1;}
        let mut node = &self.head;
        for i in 0..index {
            if let Some(ref t) = node {
                node = &t.next;
            } else {
                return -1;
            }
        }
        if let Some(ref t) = node {
            t.val
        } else {
            -1
        }
        //node.as_ref().unwrap().val
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    fn add_at_head(&mut self, val: i32) {
        //self.head = addNode(self.head, val);
        let node = self.head.clone();
        self.head = Some(Box::new(ListNode {val, next: node}));
    }
    
    /** Append a node of value val to the last element of the linked list. */
    fn add_at_tail(&mut self, val: i32) {
        self.reverse();
        self.add_at_head(val);
        self.reverse();
    }
    
    fn len(&self) -> i32 {
        let mut node = &self.head;
        let mut res = 0;
        while let Some(ref t) = node {
            res += 1;
            node = &t.next;
        }
        res
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    fn add_at_index(&mut self, mut index: i32, val: i32) {
        let len = self.len();
        if index < 0 {index = 0;}
        if index < 0 || index > len {return;}
        let mut prev = None;
        let mut remn = self.head.clone();
        for i in 0..index {
            let t = remn.unwrap();
            prev = Some(Box::new(ListNode {val: t.val, next: prev}));
            remn = t.next;
        }
        remn = Some(Box::new(ListNode {val, next: remn}));
        //prev = reverse(prev);
        while let Some(t) = prev {
            remn = Some(Box::new(ListNode {val: t.val, next: remn}));
            prev = t.next;
        }
        self.head = remn;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    fn delete_at_index(&mut self, index: i32) {
        let len = self.len();
        
        if index < 0 || index >= len {return;}
        let mut prev = None;
        let mut remn = self.head.clone();
        for i in 0..index {
            let t = remn.unwrap();
            prev = Some(Box::new(ListNode {val: t.val, next: prev}));
            remn = t.next;
        }
        if let Some(t) = remn {
            remn = t.next;
        }
        //prev = reverse(prev);
        while let Some(t) = prev {
            remn = Some(Box::new(ListNode {val: t.val, next: remn}));
            prev = t.next;
        }
        self.head = remn;
    }
    
    fn reverse(&mut self) {
        let mut node = &self.head;
        let mut res = None;
        while let Some(t) = node.as_ref() {
            res = Some(Box::new(ListNode {val: t.val, next: res}));
            node = &t.next;
        }
        self.head = res;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList::new();
 * let ret_1: i32 = obj.get(index);
 * obj.add_at_head(val);
 * obj.add_at_tail(val);
 * obj.add_at_index(index, val);
 * obj.delete_at_index(index);
 */
```