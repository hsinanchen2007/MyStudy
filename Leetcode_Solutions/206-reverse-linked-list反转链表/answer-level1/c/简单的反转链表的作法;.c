### 解题思路
此处撰写解题思路
1 step 申请一个头节点将头节点与 head 相连；
2  step 将p= head 的下一个 通过 p->next=p->next->next;
3 将 p->next 通过尾插法插入;
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
if(head==NULL)
return NULL;
struct  ListNode *prehead , *p , *q;
p=head;
prehead=(struct ListNode *)malloc(sizeof(struct ListNode));
prehead->next=head  ;// 衔接头节点;
while(p->next!=NULL && p!=NULL)
{
      // 删除节点
      q=p->next;
      p->next=p->next->next;
      //头插法
      q->next=prehead->next;
      prehead->next=q;
}
return prehead->next;
}
```

法二使用数组存数据法;
## 代码
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
struct ListNode *p  ,*prehead, *p1, *r;
int count=0;
int arry[1000000];
p1=head;
- while(p1)()]()
{
    arry[count]=p1->val;
    count++;
    p1=p1->next;
}
prehead=(struct ListNode *)malloc(sizeof(struct ListNode));
prehead->next=NULL;
r=prehead;
while(count)
{
     p=(struct ListNode *)malloc(sizeof(struct ListNode));
     p->val=arry[count-1];
     r->next=p;
     r=p;
     r->next=NULL; 
     count--;
}
return prehead->next;
}
```