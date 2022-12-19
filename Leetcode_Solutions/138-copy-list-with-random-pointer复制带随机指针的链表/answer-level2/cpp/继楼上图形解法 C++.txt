楼上 [图形法讲解](https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/yong-tu-xing-shuo-ming-jie-fa-by-commonheart/) 的很详细，我就不赘述了，这里提供一下C++版本，供C++使用者参考，看我的函数名就知道功能了

```
typedef Node node;
//1->2->3 => 1->1->2->2->3->3
void extendLinkList(node* &head) {
	if (!head)
		return;
	node* p = head;
	while (p) {
		node* r = new node;
		r->val = p->val;
		r->next = p->next;
		p->next = r;
		p = p->next->next;
	}
}

//放置好random指针
void putRandomPtr(node* &head) {
	if (!head)
		return;
	node* p = head;
	while (p) {
		if (p->random)
			p->next->random = p->random->next;
		else
			p->next->random = nullptr;
		p = p->next->next;
	}
}

//1->1->2->2->3->3 => 1->2->3 + 1->2->3
node* splitLinkList(node* head) {
	if (!head)
		return nullptr;
	node* newHead = head->next;
	node* p = newHead;
	node* q = head;
	while (1) {
		q->next = p->next;
		q = q->next;
		if (!q)
			break;
		p->next = q->next;
		p = p->next;
	}
	return newHead;
}

Node* copyRandomList(Node* head) {
	if (!head)
		return nullptr;
	extendLinkList(head);
	putRandomPtr(head);
	return splitLinkList(head);
}
```