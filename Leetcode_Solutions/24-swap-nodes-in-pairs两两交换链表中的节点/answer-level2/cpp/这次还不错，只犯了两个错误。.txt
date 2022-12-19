### 解题思路
此处撰写解题思路
关键点在于头结点，拿出当前节点的后一个结点，把它放在当前节点的前面。在更新结点。
### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        return NULL;
        ListNode *  first=(ListNode *)malloc (sizeof(ListNode));//有头结点就变得好写多了。
         ListNode *pre,*curr;   //  *curr,写成curr就不是指针了（错误1）
           ListNode *now=first;
         first->next=head;
         curr=first->next;
         for(;curr->next!=NULL;)
         {
             pre=curr->next;
             curr->next=curr->next->next;
            now->next=pre;
            pre->next=curr;
            now=now->next->next;//忘了更新now(错误2)
            curr=curr->next;
            if(curr==NULL)
            break;
         }
    return first->next  ;
    }
};
```