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
int SearchNode(struct ListNode*head,int k,int*i){
    int m;
    if(head==NULL)   return;
    m=SearchNode(head->next,k,i);
    (*i)++;
    if(*i==k)
    return head->val;
    return m>0?m:0;
}
int kthToLast(struct ListNode* head, int k){
int i=0;
return SearchNode(head,k,&i);
}
```