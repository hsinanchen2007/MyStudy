0ms
```rs
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut last = None;
        let mut cur = head;
        loop {
            if let Some(mut node) = cur {
                // node 是一个 Box 指针, 这里省略了 *
                cur = node.next;
                node.next = last;
                last = Some(node);
            } else {
                break;
            }
        }
        last 
    }
}
```

对指针的复制(Copy)是很廉价的.

## 下面是一个错误例子

516ms
```rs
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut last = None;
        let mut head = head;
        loop {
            if let Some(node) = head.as_mut() {
                // 对 Box 用 clone() 会把 Box 内部的内容 clone 一份
                let next = node.next.clone();
                node.next = last;
                last = head;
                head = next;
            } else {
                break;
            }
        }
        last 
    }
}
```
