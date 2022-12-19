### 解题思路
链表操作没有固定封装的库写着比较繁琐一些，也还好。最后一个进位可能会漏掉，
执行用时 :
12 ms
, 在所有 C 提交中击败了
96.21%
的用户
内存消耗 :
7.3 MB
, 在所有 C 提交中击败了
100.00%
的用户

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
    int temp_l1;
    int temp_l2;
    int temp;
    int iFlag = 0;
    struct ListNode* l1_t = l1;
    struct ListNode* l2_t = l2;
    struct ListNode* head = NULL;
    struct ListNode* pCur;
    struct ListNode* pPreCur = NULL;

    while (l1_t != NULL || l2_t != NULL)
    {
        temp_l1 = (NULL != l1_t)?l1_t->val:0;
        temp_l2 = (NULL != l2_t)?l2_t->val:0;

        temp = temp_l1 + temp_l2;
        if(1 == iFlag)
        {
            iFlag = 0;
            temp += 1;
        }
        struct ListNode* pCur = (struct ListNode*)malloc(sizeof(struct ListNode));
        pCur->val = temp%10;
        pCur->next = NULL;
        if(NULL == head)
        {
            head = pCur;
        }

        if(0 != temp / 10)
        {
            iFlag = 1;
        }

        if(NULL != pPreCur)
        {
            pPreCur->next = pCur;
        }
        pPreCur = pCur;

        l1_t = (NULL == l1_t)?NULL:l1_t->next;
        l2_t = (NULL == l2_t)?NULL:l2_t->next;
    }

    if(1 == iFlag)
    {
        struct ListNode* pCur = (struct ListNode*)malloc(sizeof(struct ListNode));
        pCur->val = 1;
        pCur->next = NULL;
        pPreCur->next = pCur;
    }

    return head;
}
```