### 解题思路
该题属于链表反转的题目，解题思路如下：
* 入参检查
* 将原链表反转，并计算链表节点的个数
* 根据链表节点个数，创建并初始化数组
* 从头遍历链表，并将节点的值放入数组中

本题考察**链表反转**，时间复杂度为O(N)，空间复杂度为O(N)。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize)
{
    //入参检查
    if(!head)
    {
        *returnSize = 0;
        return NULL;
    }

    //反转链表
    int len = 0;
    struct ListNode *newHead = NULL;
    struct ListNode *tmp;
    while(head)
    {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
        len++;
    }

    //创建并初始化数组
    int *result = (int*)malloc(sizeof(int) * len);
    memset(result, 0, sizeof(int)*len);

    for(int i=0; i<len; i++)
    {
        result[i] = newHead->val;
        newHead = newHead->next;
    }

    *returnSize = len;
    return result;
}
```