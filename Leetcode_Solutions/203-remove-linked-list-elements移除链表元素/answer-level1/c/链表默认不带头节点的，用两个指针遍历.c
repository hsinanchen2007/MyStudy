链表默认不带头节点的，用两个指针遍历，p,q先指向第一个结点（规定q是前驱结点），并进行判断，（如果链表只有一个元素直接返回。），如果是要删除的结点，进行删除（此处对是否为第一个结点进行判断，如果是第一个结点，则更换头节点指针，同时修改p,q指针。如果不是第一个结点， q->next=p->next;进行删除。），如果不是要删除的结点，进行下一个结点遍历，直到链表末尾。



struct ListNode* removeElements(struct ListNode* head, int val){
struct ListNode*p,*q;
	  p=head;
	  if (head==NULL)
	  {
		  return NULL;
	  }
	  q=head;
	  while (p !=NULL)
	  {
		  if (val == p->val)
		  {
			  if (p == head)
			  {
				  head=p->next;
				  //free(p);
				  q=p=head;
			  }
			  else
			  {
				  q->next=p->next;
				  p=p->next;
			  }
		  }
		  else
		  {
			  q=p;
			  p=p->next;
		  }
		  
	  }
	  return head;
}