### 解题思路
1. 遍历链表，将值从后往前放进数组中，在将数组有值的部分移到前面（注意内存重叠）
2. 不要使用memcpy，memcpy不允许内存重叠，原因请看memcpy实现源码，使用memmove，允许内存重叠
![image.png](https://pic.leetcode-cn.com/cb038cc43d4f617c5182d87445acfd03b7d40f5e442daf6e2f04c85423902b1b-image.png)

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
#define ARR_SIZE    10000
    int *stack = (int *)calloc(ARR_SIZE, sizeof(int));
    int *temp = stack + ARR_SIZE - 1;

    *returnSize = 0;

    while (head)
    {
        *temp-- = head->val;
        head = head->next;
        (*returnSize)++;
    }

    memmove(stack, temp+1, *returnSize * sizeof(int));
    
    return stack;
}
```