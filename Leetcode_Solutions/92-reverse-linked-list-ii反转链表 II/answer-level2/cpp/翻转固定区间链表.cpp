1、创建一个哑结点before，将m之前的链表连接在before之后，并用mm记录开始翻转的位置；
2、开始翻转m到n之间的链表；
3、翻转部分翻转后，mm即为翻转链表的结尾，将n之后的链表连接到mm之后；
4、最后将翻转的链表连接到before之后；

实现：
```
ListNode* reserveBetween(ListNode* head, int m, int n) {

	ListNode before(-1);
	ListNode* b = &before;
	b->next = head;

	int count = 1;
	//找到开始翻转链表的位置
	while (count < m) {
		head = head->next;
		b = b->next;
		count++;
	}
	//记录开始翻转的位置
	ListNode* mm = head;

	//翻转链表
	ListNode *q, *r;
	q = NULL;
	while (count <= n) {
		r = q;
		q = head;
		head = head->next;
		q->next = r;
		count++;
	}
	//拼接后续链表
	mm->next = head;
	//将前面没翻转的链表接上后续链表
	b->next = q;

	return before.next;
}
```
