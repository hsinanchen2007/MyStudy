### 解题思路
每次从旧链表的头部掰一个节点下来，安到新链表的头部，直到旧链表没有元素，即完成链表反转

例：
- 原始状态：旧 = 1->2->3->4->5->None，新 = None
- 第一次迭代，把 1 从旧链表上掰下来，放到新链表头部。旧 = 2->3->4->5->None，新 = 1->None
- 第二次迭代，把 2 从旧链表上掰下来，放到新链表头部。旧 = 3->4->5->None，新 = 2->1->None
- 第三次迭代，把 3 从旧链表上掰下来，放到新链表头部。旧 = 4->5->None，新 = 3->2->1->None
- 第四次迭代，把 4 从旧链表上掰下来，放到新链表头部。旧 = 5->None，新 = 4->3->2->1->None
- 第五次迭代，把 5 从旧链表上掰下来，放到新链表头部。旧 = None，新 = 5->4->3->2->1->None
- 旧链表变为 None，迭代结束

### 代码

```rust
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut old_list = head;
        let mut new_list: Option<Box<ListNode>> = None;
        
        while old_list.is_some() {
            let mut node = old_list.unwrap();
            let rem = node.next.take();
            node.next = new_list;
            new_list = Some(node);
            old_list = rem;
        }

        new_list
    }
}
```

### 执行结果
执行用时 :0 ms, 在所有 Rust 提交中击败了100.00% 的用户
内存消耗 :2.3 MB, 在所有 Rust 提交中击败了75.00%的用户