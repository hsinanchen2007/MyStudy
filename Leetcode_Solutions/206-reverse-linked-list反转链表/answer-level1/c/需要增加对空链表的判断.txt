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

//头插法，因为执行循环前需要判断head是否为空，所以包含了链表为空链表的情况
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode * Top = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    Top->next = NULL;
    while(head){
        Top->val = head->val;
        head = head->next;
        struct ListNode * New = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        New->next = Top;
        Top = New;
        
    }
    return Top->next;
}

//三指针法，关键是需要判断链表是否为空，否则会出现head->next->next不存在的情况
struct ListNode* reverseList(struct ListNode* head){
    if(!head)
        return head;
    struct ListNode *cur, *prev, *next;
    prev = head;
    cur = head->next;
    head->next = NULL;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
        


}
```