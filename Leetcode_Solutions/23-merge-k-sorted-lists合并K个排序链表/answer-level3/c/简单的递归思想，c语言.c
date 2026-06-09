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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
struct ListNode *start,*l3;
if(!l1) return l2;
if(!l2) return l1;
start=l1->val<=l2->val?l1:l2;
l3=start;
if(l1->val<=l2->val) l1=l1->next;
else l2=l2->next;
while(l1&&l2)
{
    if(l1->val<=l2->val)
    {
        l3->next=l1;
        l3=l1;
        l1=l1->next;
    }
    else
    {
        l3->next=l2;
        l3=l2;
        l2=l2->next;
    }
}
l3->next=l1?l1:l2;
return start;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
     if(listsSize==0) return NULL;
     else if(listsSize==1) return *lists;
     else if(listsSize==2) return(mergeTwoLists(*lists,*(lists+1)));
     else if(listsSize%2==0)
         return(mergeTwoLists(mergeKLists(lists,listsSize/2),mergeKLists(lists+listsSize/2,listsSize/2)));
     else
        return(mergeTwoLists(*(lists+listsSize/2),mergeTwoLists(mergeKLists(lists,listsSize/2),mergeKLists(lists+listsSize/2+1,listsSize/2))));
}
```