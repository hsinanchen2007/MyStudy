### 解题思路
用链表节点类型的数组存储每个节点，遍历完获得节点数量cnt后，直接返回下标为cnt/2的节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
   // printf("%d",head->val);
   struct ListNode *p[100];
   int cnt=0;
   while(head!=NULL)
   {
       p[cnt++]=head;
       head=head->next;
   }
    return p[cnt/2];
}
```