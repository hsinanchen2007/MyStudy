### 解题思路
我这里采用了曲线救国的思想，我用一个数组把链表的元素值都存了起来，为了提升效率，我从后往前遍历，并且保存最大值。这样可以减少一部分遍历，因为当前值若大于等于其后面元素的最大值，那么就直接赋值为0。

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
 int getLength(struct ListNode *head)
 {
     int length=0;
     while(head)
     {
         length++;
         head=head->next;
     }
     return length;
 }
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int length=getLength(head);
    int *result=(int *)malloc(sizeof(int)*length);
    int num[length];
    int index=0;

    while(head)
    {
        num[index++]=head->val;
        head=head->next;    
    }
    *returnSize=index;
    if(index==0)
    return result;

    int max=num[--index];
    while(index>=0)
    {
        if(num[index]>=max)
        {
            result[index]=0;
            max=num[index];
        }
        else
        {
            if(num[index]>=num[index+1]&&num[index]<result[index+1])
            result[index]=result[index+1];
            else{
                int i=index+1;
                for(;i<length&&num[index]>=num[i];i++);
                result[index]=num[i];
            }
        }
        index--;
    }
    return result;

}


```