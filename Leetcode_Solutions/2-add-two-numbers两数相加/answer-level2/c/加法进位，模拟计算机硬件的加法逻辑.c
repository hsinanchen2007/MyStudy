### 解题思路
![图片.png](https://pic.leetcode-cn.com/775873d611fd9ba6a7d68fa1e57c15ef4f4ead31dd9d0a59d369dbf293a6cba5-%E5%9B%BE%E7%89%87.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3;l3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=l1,*q=l2,*r=l3;
	int flag=0;
	while(p!=NULL&&q!=NULL){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		int sum=p->val+q->val+flag;
		if(sum<10){
			t->val=sum;
			flag=0;
		}else{
			t->val=sum-10;
			flag=1;
		}
		r->next=t;
		p=p->next;q=q->next;r=r->next;
	}
	while(p!=NULL){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		int sum=p->val+flag;
		if(sum<10){
			t->val=sum;
			flag=0;
		}else{
			t->val=sum-10;
			flag=1;
		}
		r->next=t;
		p=p->next;r=r->next;
	}
	while(q!=NULL){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		int sum=q->val+flag;
		if(sum<10){
			t->val=sum;
			flag=0;
		}else{
			t->val=sum-10;
			flag=1;
		}
		r->next=t;
		q=q->next;r=r->next;
	}
	if(flag==1){
		struct ListNode *t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		int sum=flag;
		t->val=sum;
		r->next=t;
	}
	return l3->next;
}


```