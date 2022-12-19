思路还是大众的思路，依次遍历原链表并比较插入到新的链表中去。只不过Option<Box<ListNode>>让我快要疯了，整整跟编译器斗争了一天，给用Rust做链表题的同学提供个参考,废话不多说看代码。
```rust
pub fn insertion_sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
	if head.is_none() { return None }
	let mut head = head.unwrap();
	let mut current = head.next.take();
	let mut result = ListNode::new(-1);
	result.next = Some(Box::new(ListNode::new(head.val)));
	let mut result = Some(Box::new(result));
	while current.is_some() {
		let mut pre = result.as_mut().unwrap();  //持有一个链表节点的可变引用
		let cu_v = current.as_ref().unwrap().val;
		while pre.next.is_some() {
			if pre.next.as_ref().unwrap().val >= cu_v {   //找到应该插入在哪一个节点之后
				break;
			}
			pre = pre.next.as_mut().unwrap();  //将当前可变引用指向下一个节点
		}
		let temp = pre.next.take();
		let mut data = ListNode::new(cu_v);
		data.next = temp;
		pre.next = Some(Box::new(data)); 
		current = current.unwrap().next.take();
	}
	return result.unwrap().next;
}
```
话说执行时间竟然32ms,和之前的那些题目的0ms反差有点大,有知道原因的大佬请告知