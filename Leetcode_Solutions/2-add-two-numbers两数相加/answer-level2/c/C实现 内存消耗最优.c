### 解题思路
先判断两个链表长度，找到较长的链表；
将较短链表加到较长链表上，考虑进位；
只会最多消耗一个节点的内存，内存消耗最优

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
    int len1 = 0,len2 = 0;
    struct ListNode *tmp1 = l1;
    struct ListNode *tmp2 = l2;
    struct ListNode *last = NULL;
    int flag = 0;
    while(tmp1 != NULL)
    {
        len1++;
        tmp1 = tmp1->next;
    }
    while(tmp2 != NULL)
    {
        len2++;
        tmp2 = tmp2->next;
    }
    if(len1 >= len2)
    {
        tmp1 = l1;
        tmp2 = l2;
    }
    else
    {
        tmp1 = l2;
        tmp2 = l1;       
    }
    while(1)
    {
        tmp1->val = tmp1->val + tmp2->val + flag;
        flag = tmp1->val / 10;
        tmp1->val = tmp1->val % 10;
        if(tmp1->next == NULL || tmp2->next == NULL)
        {
            break;
        }
        else
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    while(tmp1->next != NULL)
    {
        tmp1 = tmp1->next;
        tmp1->val = tmp1->val + flag;
        flag = tmp1->val / 10;
        if(flag == 0)
        {
            break;
        }
        else
        {
            tmp1->val = tmp1->val % 10;
        }
    }
    if(flag == 1)
    {
        last = (struct ListNode *)malloc(sizeof(struct ListNode));
        last->val = 1;
        last->next = NULL;
        tmp1->next = last;
    }
    if(len1 >= len2)
    {
        return l1;
    }
    else
    {
        return l2;
    }
}
```