我们可以使用两个指针去遍历链表，先将第一个指针 `b` 移动K步，再将第二个指针 `preK` 从链表开头进行遍历。当 `b.next` 为空时，指针 `b` 就是倒数第一个节点，指针 `preK` 就是第 K-1 个节点。

如果k的长度大于链表长度，那么可以在第一次移动指针 `b` 时计算链表长度。当 `b` 指针移动k步时，如果K的长度大于链表节点的话，那么 `b` 指针就会为 null，也就计算出了链表长度 `n` 的值，然后将 `k mod n` 重新计算 `b` 指针的位置。

第一次写解题，如果有什么错误或者建议，请指出。

```java
public ListNode rotateRight(ListNode head, int k) {
	int n = 0 ;
	ListNode b = head ;
	while(n < k && b != null){
		b = b.next ;
		n ++ ;
	}
	if(n == 0) return head ;
	// 如果b为 null，那么k大于节点长度，重新计算。
	if(b == null){
		k %= n ;
		if(k == 0) return head;
		for(b = head,n = 0;n < k;n ++){
			b = b.next ;
		}
	}
	ListNode kPre = head ;
	while(b.next != null){
		b = b.next ;
		kPre = kPre.next ;
	}	
	// 将第 k-1 个后面的节点移动到 head 前。
	ListNode kNode = kPre.next ;
	kPre.next = null ;
	b.next = head ;
	return kNode ;
}
```