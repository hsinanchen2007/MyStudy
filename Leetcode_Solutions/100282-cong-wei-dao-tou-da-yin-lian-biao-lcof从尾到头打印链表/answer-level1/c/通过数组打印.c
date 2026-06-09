### 解题思路
此处撰写解题思路
顺序读取链表中的值，存入数组中，创建新数组，将数组倒序存入新数组中。
returnSize是最终返回数据的长度
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
    int* out=(int *)malloc(sizeof(int)*(10000));
    int len=0;
    while(head)
    {
        out[len++]=head->val;
        head=head->next;
    }
    int* realOut=(int*)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++)
    {
        realOut[i]=out[len-1-i];
    }
    free(out);
    *returnSize=len;
    return realOut;

}
```