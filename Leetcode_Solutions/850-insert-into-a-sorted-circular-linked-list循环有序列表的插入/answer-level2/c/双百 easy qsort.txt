### 解题思路
此处撰写解题思路

### 代码

```c
/**给链表用qsort排序，然后就ok了
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 * };
 */

int Com(const void *a, const void * b)
{
	struct Node a1 = *(struct Node *)a;
	struct Node b1 = *(struct Node *)b;
	return a1.val > b1.val;
}

void Sort(struct Node *head, int num)
{
	struct Node *buf = (struct Node *)malloc(sizeof(struct Node) * num);
	struct Node *p = head;
	for (int i = 0; i < num; i++) {		
		buf[i].val = p->val;
		p = p->next;
	}
	qsort(buf, num, sizeof(struct Node), Com);
	p = head;
	for (int i = 0; i < num; i++) {		
		p->val = buf[i].val;
		p = p->next;
	}
	free(buf);
}

struct Node* insert(struct Node* head, int insertVal) {

    if (head == NULL) {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->val = insertVal;
        head->next = head;
        return head;
    }
 	struct Node *p = head;
	struct Node *bef = NULL;
	struct Node *aft = NULL;
	int cnt = 0;
	while(p != NULL) {
		p = p->next;
		cnt++;
		if (p == head) {
			break;
		}
	}
    //printf("cnt %d", cnt);
	p = head;
	struct Node *q = (struct Node *)malloc(sizeof(struct Node));
	q->val = insertVal;
	q->next = head->next;
	head->next = q;

	Sort(head, cnt + 1);
	return head;
}


```