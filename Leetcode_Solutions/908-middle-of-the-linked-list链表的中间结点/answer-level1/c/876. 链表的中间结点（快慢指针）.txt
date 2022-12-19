# 876. 链表的中间结点

​	so easy！采用快慢指针来处理该题，最开始快慢指针都指向第一个节点，然后每次一循环慢指针+1,快指针+2，直到快指针到达末尾。（PS：该题描述有些问题，应该是不包含头结点的链表）

​	**1.当总元素为奇数个(例：1 2 3 4 5)**

​		慢指针：1	快指针：1

​		慢指针：2	快指针：3

​		慢指针：3	快指针：5	结束（快指针 -> next == NULL）

​	**2.当总元素为偶数个(例：1 2 3 4 5 6)**

​		慢指针：1	快指针：1

​		慢指针：2	快指针：3

​		慢指针：3	快指针：5

​		慢指针：4	快指针：7	结束（快指针 == NULL）




```c
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode *p = head;
	struct ListNode *q = head;
	while(q != NULL && q->next != NULL){
        p = p->next;     
		q = q->next->next;  
	}
	return p;
}
```

