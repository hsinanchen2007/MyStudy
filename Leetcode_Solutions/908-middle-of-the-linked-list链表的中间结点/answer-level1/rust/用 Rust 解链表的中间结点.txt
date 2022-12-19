## 解题思路
快慢向后移动头部结点：slow_h 循环向后移动一个结点，fast_h 循环向后移动两个结点。当 fast_h 移动为空时，slow_h 正好在链表的中间结点。

用到的方法：
* `as_ref()` 方法做引用到引用的转换，把 &Option<T> 转换为 Option<&T>；
* `unwrap()` 方法作用是，当枚举体 Option<T> 是 Some(v) 时，移出 v；
* `is_some()` 方法作用是，当 Option 是 Some 时返回 true；
* `clone()` 方法返回一个值的拷贝，对结构体 ListNode 实现了 Trait std::clone::Clone。

单链表定义
```Rust
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}
```


## 完整代码
```Rust
impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut fast_h = &head;
        let mut slow_h = &head;
        while fast_h.is_some() && fast_h.as_ref().unwrap().next.is_some() {
            slow_h = &slow_h.as_ref().unwrap().next;
            fast_h = &fast_h.as_ref().unwrap().next.as_ref().unwrap().next;
        }
        slow_h.clone()
    }
}
```