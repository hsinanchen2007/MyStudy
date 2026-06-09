![1.jpg](https://pic.leetcode-cn.com/4dc2bb57c773ab662bebbef8612c1e1c74d28dee6d2a936493f551ce9d2f6e20-1.jpg)
1、先让t向前走K步；
2、head和t同步前进，t到结尾，head到目标。
```
	struct ListNode*t = head;
	while (k--){
		t = t->next;
	}
	while (t){
		t = t->next;
		head = head->next;
	}
	return head->val;
```

