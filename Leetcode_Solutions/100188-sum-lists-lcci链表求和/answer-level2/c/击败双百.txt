### 解题思路
此处撰写解题思路
直接上代码
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
    int jinwei=0;
    struct ListNode* pre=(struct ListNode*)malloc(sizeof(struct ListNode)), *tmp=pre;
    pre->next=NULL;
    while(l1!=NULL||l2!=NULL){
        int num1= l1==NULL ? 0 : l1->val;
        int num2= l2==NULL ? 0 : l2->val;
        
        struct ListNode*node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=(num1+num2+jinwei)%10;
        jinwei=(num1+num2+jinwei)/10;
        node->next=NULL;
        tmp->next=node;
        tmp=tmp->next;
        if(l1!=NULL)
        l1=l1->next;
        if(l2!=NULL)
        l2=l2->next;
    }
    if(jinwei>0){
        struct ListNode*node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=jinwei;
        node->next=NULL;
        tmp->next=node;
    }
    tmp=pre->next;
    free(pre);
    return tmp;
}
```