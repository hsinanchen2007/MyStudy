### 解题思路
此处撰写解题思路
Line 207: Char 3: runtime error: load of null pointer of type 'int' (__Serializer__.c)
测试的时候经常出现这个问题，测试用例是输入空链表"[]"，此时的处理需要让 *returnSize = 0，
否则输出为 "]" ，提示不通过
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
int* reversePrint(struct ListNode* head, int* returnSize){
    if (head == NULL || returnSize == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
        

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* tmp = head;
    int num = 0, i = 0;
    int *ret = NULL;

    while (tmp != NULL)
    {
        num++;
        curr = tmp;
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
    }

    *returnSize = num;
    ret = (int *)malloc(sizeof(int) * (num + 1));

    while (curr != NULL)
    {
        ret[i++] = curr->val;
        curr = curr->next;
    }

    return ret;
}
```