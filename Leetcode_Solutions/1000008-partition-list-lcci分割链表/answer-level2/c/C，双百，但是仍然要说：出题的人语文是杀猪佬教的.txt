![1.jpg](https://pic.leetcode-cn.com/5e86577d1878c3b1bac55596e7cfca25a9f6c8a45aeffce208227c9c0446acad-1.jpg)

```
    if (!head || !head->next)  return head;
	struct ListNode* h1 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t1 = h1;
	struct ListNode* h2 = (struct ListNode*)malloc(sizeof(struct ListNode)), *t2 = h2;
	t1->next = NULL; t2->next = NULL;
	while (head){
		if (head->val < x){
			t1->next = head;
			t1 = t1->next;
		}
		else{
			t2->next = head;
			t2 = t2->next;
		}
		head = head->next;
	}
	t1->next = h2->next;
	t2->next = NULL;
	return h1->next;
```
