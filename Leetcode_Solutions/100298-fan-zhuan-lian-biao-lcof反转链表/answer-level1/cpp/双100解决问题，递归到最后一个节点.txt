### 解题思路
此处撰写解题思路

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
    ListNode* reverse(ListNode* head){
        //node = head;
        if(head->next==NULL){
            return head;
        }
        else{
             ListNode* node=NULL;
             node = reverse(head->next);
             node->next = head;
             head->next = NULL;
             return head;
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* node=head;
        while(node->next!=NULL){
            node = node->next;
        }
        reverse(head);
        return node;
    }
};
```