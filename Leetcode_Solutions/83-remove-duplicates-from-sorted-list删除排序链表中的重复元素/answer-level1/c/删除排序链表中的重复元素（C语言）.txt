### 解题思路
  这是排序链表，可以利用该性质 与 pre->val == pre->next->val 判断删除与否

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){

    if (head == NULL) {
	    return NULL;
    }

    struct ListNode *pre = head;
    struct ListNode *q = NULL;

    while (pre != NULL && pre->next != NULL) {

	    if(pre->val == pre->next->val) {
		    q = pre->next;
		    pre->next = q->next;
		    free(q);
	    }
	    else {
		    pre = pre->next;
        }
    }

	return head;
}
```