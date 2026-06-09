这应该是safe下的最优解法了，求问如何用unsafe指针实现O(1)额外空间
```rust
impl Solution { 
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> { 
        let mut node = head; 
        let mut res = None;
        while let Some(t) = node { 
            res = Some(Box::new(ListNode{val: t.val, next: res}));  
            node = t.next; 
        }
        res 
    } 
}
```
利用嵌套数据类型的构造顺序和读取顺序相反进行反转，但是不具有通用性
嵌套数据类型的一个问题就是不能像传统C指针一样进行随意更改指向