### 解题思路
1，声明3个指针，Pre指向删除的前一个节点，Del指向要删除的节点，Net为遍历指针
2，做一次遍历，Net和Del指针间隔n个节点同时移动，当Net结束时Del指向要删除的节点
3，删除节点，特殊处理删除头节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int     iNodeNum       = 1;
    struct ListNode*    pPreNode    = NULL;
    struct ListNode*    pDelNode    = NULL;
    struct ListNode*    pNetNode    = NULL;

    if (NULL == head)
    {
        return NULL;
    }

    pPreNode = head;
    pDelNode = head;
    pNetNode = head->next;

    while (NULL != pNetNode)
    {
        if (iNodeNum >= n)
        {
            pPreNode = pDelNode;
            pDelNode = pDelNode->next;
        }
        iNodeNum += 1;

//        printf("num=%d, Pre=%d, Del=%d, Net=%d\n", iNodeNum, pPreNode->val, pDelNode->val, pNetNode->val);

        pNetNode = pNetNode->next;
    }

    if (iNodeNum >= n)
    {
        if ((pDelNode == head) && (pPreNode == pDelNode))
        {
            head = head->next;
        }
        else
        {
            pNetNode = pDelNode->next;
            pPreNode->next = pNetNode;
            free(pDelNode);
        }
    }
    return head;
}
```