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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* reversePrint(struct ListNode* head, int* returnSize)
{
    int* Arr = (int*)malloc(sizeof(int) * 10000);
    memset(Arr,0,sizeof(int) * 10000);
    if(head == NULL)
    {
        *returnSize = 0;
        return Arr;
    }
    int i = 0;
    while(head)     //遍历链表，将元素存入数组
    {
        Arr[i++] = head->val;
        head = head->next;
    }
    *returnSize = i;
    for(int j = 0, k = i - 1; j < k; ++j,--k)   //反转数组
    {
        swap(&Arr[j],&Arr[k]);
    }
    return Arr;
}


```