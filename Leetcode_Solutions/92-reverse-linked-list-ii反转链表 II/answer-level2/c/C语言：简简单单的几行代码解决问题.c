![QQ截图20190724091927.png](https://pic.leetcode-cn.com/ac663497ece0d5232d67c370b7bdf7abc01482604523fadda63d35a119c5db13-QQ%E6%88%AA%E5%9B%BE20190724091927.png)

```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL || m>=n) return head;
	struct ListNode *p1,*p2,*p3;
	struct ListNode HEAD;	
	HEAD.next = head;

	//保存第一个前驱节点
	p1 = &HEAD;
	for (int i = 1; i < m; ++i) p1 = p1->next;
	p2 = p1->next;

	//翻转[m, n]区间链表
	for(int i = 0; i < n-m; ++i) {
		p3        = p2->next;//每一次都相当于原地翻转
		p2->next  = p3->next;
		p3->next  = p1->next;
		p1->next  = p3;
	}
	return HEAD.next;
}
```
