### 解题思路
先将为NULL的情况排除，再把极端情况排除（一条链表的末尾大于另一条链表的头），把l2中大于l1头的所有元素与l1合并，再把大于l1头与
小于l1尾的进行比较插入，再把大于l1尾的l2元素插入l1尾。

### 代码

```c
/* struct ListNode {
     int val;
      struct ListNode *next;
  };*/
 

int size(struct ListNode* l1, struct ListNode** l2)
 {
	 int i;
     struct ListNode* l3;
	 for (i = 0; l1 != NULL; l1 = l1->next)
	 {
         l3=l1;
		 i++;
	 }
	 *l2 = l3;
	 return i;
 }
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	 struct ListNode *head,*head2,*ptail=NULL,*ptail2=NULL,*pcur;
	 head = l1;
	 head2 = l2;
	 int i,i2;
	 i2 = size(l2,&ptail2);
	 i = size(l1,&ptail);
	 if (l1 == NULL&&l2 == NULL)
	 {
		 goto end;
	 }
	 else if (l1 == NULL || l2 == NULL)
	 {
		 l1 = l1 > l2 ? l1 : l2;
		 goto end;
	 }
	 else{
		 if (ptail2->val <= head->val)
		 {
			 ptail2->next = l1;
			 l1 = head2;
			 goto end;
		 }
		 if (ptail->val <= head2->val)
		 {
			 ptail->next = head2;
			 goto end;
		 }
         if(l2->next!=NULL)
         {
		  for (; head->val >= l2->next->val; l2 = l2->next);
         }
		 if (head->val >= l2->val)
		 {
			 pcur = l2->next;
			 l2->next = head;
			 head = head2;
			 l2 = pcur;
		 }
			 for (; i > 0; l1 = l1->next)
			 {
                 if(l1->next==NULL)
                 {
                     break;
                 }
				 if (l2!=NULL&&l2->val >= l1->val&&l2->val <= l1->next->val)
				 {
					 while (l2 != NULL&&l2->val <= l1->next->val)
					 {
						 pcur = l2->next;
						 l2->next = l1->next;
						 l1->next = l2;
						 l1 = l2;
						 l2 = pcur;
					 }
				 }
				 i--;
			 }
			 if (l2!=NULL&&l2->val > ptail->val)
			 {
				 ptail->next = l2;
			 }
		 l1 = head;
	 }
 end:
	 return l1;
}
```