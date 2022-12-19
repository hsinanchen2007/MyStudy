1、由于头结点可能会被删除，所以创建一个新结点newNode，将不重复的结点连在新结点之后即可；
2、创建两个指针l,r，开始都指向头结点；
3、r向后遍历，如果r值与l值相等，记录数量count;
4、当r与l不相等时，判断count是否大于1，大于1，即为重复，l移动到r处，同时将count置0，如果小于等于1，不是重复元素，将该结点连接到newNode之后，同时将newNode后移，l移动到r处，count置0；
5、最后，看count是否大于1，大于1，直接将结尾指向NULL，否则，将l连接到后面；

```
ListNode* deleteDuplucates(ListNode* head) {
	if (head == NULL) return head;

	ListNode* newNode = (ListNode*)malloc(sizeof(struct ListNode));

	ListNode* l = head; 
	ListNode* r = head;
	ListNode* p = newNode;

	int count = 0;
	while (r != NULL) {
		//两数值相等，r指针向后移动
		if (r->val == l->val) {
			count++;
			r = r->next;
		}
		else {
			if(count <= 1){ 
				p->next = l;
				p = p->next;
			}
			l = r;
			count = 0;
		}
	}
	if (count > 1) {
		p->next = NULL;
	}
	else {
		p->next = l;
	}
	return newNode->next;
}
```
