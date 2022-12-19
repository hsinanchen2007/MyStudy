### 解题思路
记录下所有出现过的节点并删除重复出现的节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* removeDuplicateNodes(struct ListNode* head){
    int a[20000]={0};
    ListNode *q=head,*pre=q;
    while(q!=NULL){
        int i=q->val;
        if(a[i]==0){
            a[i]++;
            pre=q;
            q=q->next;
        }else{
            ListNode*t=q;
            pre->next=q->next;
            q=q->next;
            free(t);
        }
    }
    return head;
}
```