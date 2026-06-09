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
bool hasCycle(struct ListNode *head) {
     struct ListNode *p=head,*q=head;
     if(!p) return false;
     if(!q->next) return false;
     q=q->next;
     while(p&&q&&q->next){
         if(p==q) return true;
         if(p&&q&&q->next){
             p=p->next; q=q->next->next;
         }
     }
     return false;
}
```