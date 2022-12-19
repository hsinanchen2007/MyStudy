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


struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode* cur = reverseList(head->next);   //此时cur 为末尾的元素
    head->next->next = head;   //head 此时等于4， head->next == 5 head->next->next == 5->4
    head->next = NULL;   //置NULL，防止出错
    return cur;
        

}


```