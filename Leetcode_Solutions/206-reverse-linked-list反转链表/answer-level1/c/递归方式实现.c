### 解题思路
此处撰写解题思路

### 代码
使用递归的方式实现
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
     if (!head||!head->next){
         return head;
     }
     struct ListNode* temp;
     struct ListNode* newHead;
     temp = head->next;
     newHead =reverseList(head->next);
     temp->next = head;
     head->next = NULL;
     return newHead;
    
}
```