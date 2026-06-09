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
//递归
struct ListNode *OpDirection(struct ListNode *low,struct ListNode *fast,bool *judge)
{
    if(!judge) return NULL;//不需要再判断
    if(!fast)//链表长度为奇数
    {
        return low->next;
    }
    if(!fast->next)//链表为偶数
    {
        struct ListNode *q=low->next;
        if(low->val!=q->val)*judge=false;
        return q->next;
    }
    struct ListNode *tail=OpDirection(low->next,fast->next->next,judge);
    if(low->val!=tail->val)(*judge)=false;
    return  tail->next;
}
bool isPalindrome(struct ListNode* head){
    if(!head||!head->next)
    return true;
    bool judge=true;
    OpDirection(head,head->next,&judge);
    return judge;
}

```
```c
//存储法
int getLength(struct ListNode *head)
{
    int length=0;
    while(head)
    {
        length++;
        head=head->next;
    }
    return length;
}
bool isPalindrome(struct ListNode* head){
    if(!head)return true;
    int length=getLength(head);
    int nums[length];
    int index=0;
    while(head)
    {
        nums[index++]=head->val;
        head=head->next;
    }
    int an_index=0;
    index--;
    while(an_index<index&&nums[an_index]==nums[index])
    {
        an_index++;
        index--;
    }
    if(an_index<index)return false;
    return true;
    
}
```
