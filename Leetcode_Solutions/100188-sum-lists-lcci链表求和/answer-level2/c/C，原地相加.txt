![1.jpg](https://pic.leetcode-cn.com/d0d5079f19b62dd18435f9323a220bc7a67894fa62e9bd5177c37f21927408c4-1.jpg)

```
	struct ListNode *head = l1;
	int t = 0, add = 0;
	while (l1->next&&l2->next){
		t = l1->val + l2->val + add;
		add = t > 9 ? 1 : 0;
		l1->val = t > 9 ? t % 10 : t;
		l1 = l1->next;
		l2 = l2->next;
	}
	t = l1->val + l2->val + add;
	add = t > 9 ? 1 : 0;
	l1->val = t > 9 ? t % 10 : t;
	if (l2->next)
		l1->next = l2->next;
	while (l1->next){
		l1 = l1->next;
		t = l1 ->val + add;
		add = t > 9 ? 1 : 0;
		l1->val = t > 9 ? t % 10 : t;
	}
	if (add){
		l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
		l1->next = l2;
		l2->val = 1;
		l2->next = NULL;
	}
	return head;
```

