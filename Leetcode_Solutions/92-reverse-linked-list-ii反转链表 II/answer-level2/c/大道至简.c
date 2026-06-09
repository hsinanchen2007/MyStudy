### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
	int i=0,j,t ;
	int *a=(int*)malloc(sizeof(int)*(n-m+1));

	struct ListNode *p = head,*q = head;

	while(q != NULL)
	{
		i++;
		q = q->next;
	}
	if(i == 1)
		return head;

	if(p == NULL || m==n)
		return head;

	for(i=1; i<m; i++)
	{
		p = p->next;
	}

	q = p;
	for(i=0; i<=n-m; i++)
	{
		a[i] = p->val;
		p = p->next;
	}

	for(i=0,j=n-m; i<(n-m+1)/2; i++,j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	for(i=0; i<=n-m; i++)
	{
		q->val = a[i];
		q = q->next;
	}

	return head;

}
```