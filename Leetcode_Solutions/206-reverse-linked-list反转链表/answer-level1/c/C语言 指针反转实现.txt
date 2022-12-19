### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
     int val;
     struct ListNode *next;
 }ListNode,*LinkList;

struct ListNode* reverseList(struct ListNode* head){
    if(!head) return NULL;
    else if(head->next == NULL)return head;
//struct ListNode p=(struct ListNode *)malloc (sizeof(struct ListNode));
LinkList nu=(LinkList)malloc(sizeof(ListNode));
nu =NULL;
LinkList end=head->next;
LinkList p=nu;
LinkList temp = head;

while(end != NULL){
    temp->next=p;
    p=temp;
    temp=end;
    end = end->next;
}
temp->next=p;
return temp;
 
}


```