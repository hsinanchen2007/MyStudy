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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    int temp;
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct ListNode *p=l1;
    struct ListNode *q;
    struct ListNode *Head = (struct ListNode*)malloc(sizeof(struct ListNode));

    while(p->next!=NULL)   p=p->next;
      
    p->next=l2;//连接两个链表
    Head->next=l1;//添加头节点

    for(p=Head->next;p->next!=NULL;p=p->next)//选择排序
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(p->val>q->val)
            {
                temp=p->val;
                p->val=q->val;
                q->val=temp;
            }
        }
    
	return Head->next;
}

```