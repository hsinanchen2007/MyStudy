### 解题思路
见代码注释部分，很详尽。

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
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    //1.求出链表的长度
    int len=0;
    struct ListNode *curr=head;
    while(curr!=NULL)
    {
        len++;
        curr=curr->next;
    }
    int *ans=(int *)malloc(sizeof(int)*len);  //申请内存空间，返回数组
    *returnSize=len;                          //返回的数组长度
    curr=head;
    
    //2.寻找链表中的下一个更大节点
    struct ListNode *p=NULL;
    int i=0;  //保存数组中的变量
    while(curr->next!=NULL)
    {
        p=curr->next;
        while(p!=NULL)
        {
            if(p->val>curr->val)
            {
                ans[i++]=p->val;
                break;
            }
            else
                p=p->next;
        }
        if(p==NULL)
            ans[i++]=0;
        curr=curr->next;
    }
    ans[i]=0;
    return ans;
}
```