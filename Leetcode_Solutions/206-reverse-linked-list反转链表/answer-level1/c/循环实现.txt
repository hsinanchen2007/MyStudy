### 解题思路
此处撰写解题思路
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)    return;
    struct ListNode* prev = NULL, *cur = head, *nextl = NULL;
	while(1)
	{
        if(cur->next != NULL)
        {
		    prev = cur->next;
        }
        else
        {
            cur->next = nextl;
            return cur;
        }
		cur->next = nextl;
        nextl = cur;
        cur = prev;
	}
}
