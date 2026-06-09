### 解题思路
将L1的内存空间，作为数据交换区；
根据l1->next l2->next,是否为空，分情况讨论；

注意：
    MALLOC之后的内存空间，记得清零；否则，会有意外收获；

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
    struct ListNode* out;
    struct ListNode* tail;
    out = l1;
    int add= 0;
    add += l1->val+l2->val;
    l1->val=add%10;
    add/=10;
    while(l1->next!=NULL&&l2->next!=NULL)
    {
        l1 = l1->next;
        l2 = l2->next;
        add += l1->val+l2->val;
        l1->val=add%10;
        add/=10;
    }
    while(l1->next==NULL&&l2->next!=NULL)
    {
        tail = malloc(sizeof(struct ListNode));// clear zero
        memset(tail,0,sizeof(struct ListNode));
        l2 = l2->next;
        l1->next = tail;
        l1=l1->next;
        add += l1->val+l2->val;
        l1->val=add%10;
        add/=10;
    }
    while(add!=0)
    {
            
            if(l1->next==NULL)
            {
                tail = malloc(sizeof(struct ListNode));
                memset(tail,0,sizeof(struct ListNode));
                l1->next = tail;
                l1=l1->next;
                l1->val=add;
                add/=10;
            }  
            else
            {
                l1=l1->next;
                add =add+ l1->val;
                l1->val=add%10;
                add/=10;
            }
           
    }
    
    return out;
}
```