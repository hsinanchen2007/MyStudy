### 解题思路
用三个指针进行翻转
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
    if(!head){
        return NULL;
    }//若链表为空
    else if(!head->next)
    {
        return head;
    }//若链表只有一个结点
    else{
        struct ListNode* tp1=head->next;
        head->next=head->next->next;
        tp1->next=head;
    
    struct ListNode* tp2=head->next;
    for(;head->next!=NULL;){
        head->next=tp2->next;
        tp2->next=tp1;
        tp1=tp2;
        tp2=head->next;
        

    }
    return tp1;
    }//一般情况

  
}
```