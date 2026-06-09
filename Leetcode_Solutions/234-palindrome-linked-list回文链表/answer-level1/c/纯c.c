### 解题思路
将链表后半部分逆置，然后前半部分与后半部分一一对比

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head) {
	struct ListNode *p = head;
	int num = 0;			//节点总数目
	int move;			//往前移动的步数
	while (p != NULL) {
		num++;
		p = p->next;
	}
	if (num == 1||num==0) {
		return true;
	}
	if (num % 2 == 0) {
		move = num / 2 - 1;
	}
	if (num % 2 != 0) {
		move = num / 2;
	}
	struct ListNode *p_pre = head;			//前半部分的最后一个节点

	while (move != 0) {
		p_pre = p_pre->next;
		move--;
	}
	p = p_pre->next;
	struct ListNode *w_pre = p;		//后半部分的第一个节点
	struct ListNode *w = w_pre->next;
	while (w != NULL) {
		p->next = w->next;
		w->next = w_pre;
		w_pre = w;
		w = p->next;
	}
	int test = 1;
	while (w_pre != NULL) {
		if (head->val != w_pre->val) {
			test = 0;
			break;
		}
		head = head->next;
		w_pre = w_pre->next;
	}
	if (test == 1)
		return true;
	if (test == 0)
		return false;
	return 0;

}
```