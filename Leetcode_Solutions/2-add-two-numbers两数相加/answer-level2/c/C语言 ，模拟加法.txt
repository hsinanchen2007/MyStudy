### 解题思路
模拟加法，满十进一，尾插节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int tmp=0;
    int x=0;
    int y=0;
    int num=0;
    Node *newhead=(Node*)malloc(sizeof(Node));
    Node* ret=newhead;
    while(l1 || l2)
    {
        x=(l1!=NULL)? l1->val:0;
        y=(l2!=NULL)? l2->val:0;
        num=x+y+tmp;
        if(num>9)
        {
            tmp=1;
            num=num%10;
        }
        else
        {
            tmp=0;
        }
        Node *nodetmp=(Node*)malloc(sizeof(Node));
        nodetmp->val=num;
        newhead->next=nodetmp;
        newhead=nodetmp;
        
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
    }
    if(tmp==1)
    {
         Node *nodetmp=(Node*)malloc(sizeof(Node));
        nodetmp->val=1;
        newhead->next=nodetmp;
        newhead=nodetmp;   
    }
    newhead->next=NULL;
    return ret->next;
}

```