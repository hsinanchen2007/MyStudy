### 解题思路
只需要改变两个节点之间的指向即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
   struct ListNode*pre=NULL,*cur=head;
   while(cur){
       struct ListNode*nex=cur->next;
       cur->next=pre;
       pre=cur;
       cur=nex;
   }
   return pre;
}
```