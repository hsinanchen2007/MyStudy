```
代码块/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//单向链表的删除

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    struct ListNode*pTemp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*pNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    int m = 0;
    pTemp = head;
    int i;
    //计算链表的长度
    while(pTemp != NULL)
    {
        m++;
        pTemp = pTemp->next;
    }
    i = m - n +1;
    //如果是头
    if(i == 1)
    {
        pTemp = head;
        head = head->next;
        free(pTemp);
        pTemp = NULL;
    }
    //如果不是头
    else 
    {
        pTemp = head;
        for(int j = 1;j< i - 1; j++)
        {
            pTemp = pTemp->next;
            
        }
        pNode = pTemp->next;
        pTemp->next = pTemp->next->next;
        free(pNode);
        pNode = NULL;
    }
    return head;
}


```
