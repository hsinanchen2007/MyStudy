最开始尝试*while let*
```
\\...
while let (Some(_), Some(s)) = (&fast, &fast.as_ref().unwrap().next) {
    fast = &s.as_ref().next;
    slow = &slow.as_ref().unwrap().next;
}
\\...
```
但这样即便第一项*False*也还会检查第二项，导致*unwrap()*返回错误
所以参考了已有答案 [rust.链表的中间节点](https://leetcode-cn.com/problems/middle-of-the-linked-list/solution/rustlian-biao-de-zhong-jian-jie-dian-by-xian-za-zh/)

网站调试慢，自己写了测试用代码，结合题目中注释内容
```
pub struct Solution;
fn main() {
    let head = simple_linear_list(5);
    show_list(&head);
    let cut = Solution::middle_node(Some(Box::new(head))).unwrap();
    show_list(&cut);
}

///return head node, make sure length>0
fn simple_linear_list(length: i32) -> ListNode {
    let mut head = ListNode::new(1);
    let mut n = &mut head;
    for i in 2..length + 1 {
        n.next = Some(Box::new(ListNode::new(i)));
        n = n.next.as_mut().unwrap();
    }
    head
}

fn show_list(l: &ListNode) {
    let mut t = l;
    while let Some(_) = &t.next {
        print!("{},", t.val);
        t = &t.next.as_ref().unwrap();
    }
    println!("{}", t.val);
}
```
