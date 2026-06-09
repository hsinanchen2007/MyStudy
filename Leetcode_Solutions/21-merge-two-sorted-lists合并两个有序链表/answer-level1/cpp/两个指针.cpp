### 解题思路
两个指针同时向后指，谁小添加到新链表尾，谁先变为NULL，说明谁已经到表尾，然后直接将另一个链表添加到新链表表尾。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1; 
            ListNode* p=l1;
            ListNode* q=l2;
            ListNode* node=new ListNode(0);
            ListNode* resNode=node;
            while(p!=0 && q!=0){
                if(p->val<= q->val){
                    node->next=p;
                    node=p;
                    p=p->next;
                }else{
                    node->next=q;
                    node=q;
                    q=q->next;
                }
            }
            if(p==NULL){
                node->next=q;
            }else{
                node->next=p;
            }
            return resNode->next;
    }
};
```