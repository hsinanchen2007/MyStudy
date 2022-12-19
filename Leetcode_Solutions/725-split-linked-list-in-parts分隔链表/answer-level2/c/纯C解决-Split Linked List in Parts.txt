### 解题思路
这道题只要想清楚了，那么就是非常简单的题目了。主要是注意三个问题：
```
1.每个子链表多长

2.如果链表的长度需要给后面的Part置为空

3.这里存的链表而不是链表数组
```
解决方案：
```
1.由于是平分链表为K个，那么毫无疑问，子链表的长度至少为length/k，若存在余数，则还需要+1

2.等分割完毕，若链表指针数组还未填满，则说明链表的长度不足K，那么置空就行

```



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
 int getLength(struct ListNode* root)
 {
     int length=0;
     while(root)
     {
         root=root->next;
         length++;
     }
     return length;
 }
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    int length=getLength(root);
    struct ListNode **result=(struct ListNode **)malloc(sizeof(struct ListNode*)*k);
    struct ListNode* pre;
    int index=0;

    int base=length/k;
    int remainder=length%k;
    *returnSize=k;

    while(root)
    {
        int i;
        result[index]=root;
        for(i=0;i<base;i++)
        {
            pre=root;
            root=root->next;
        }
        if(remainder)//确保前面的长后面的短
        {
            pre=root;
            remainder--;
            root=root->next;
        }
        pre->next=NULL;

        index++;
    }
    for(index;index<k;index++)//若长度不够，置空
    result[index]=NULL;
    return result;
}
```