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
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* mid = midNode(head);
        ListNode* p1 = head;
        ListNode* p2 = mid->next;
        mid->next = NULL;
        p2 = reverse(p2);
        while(p1||p2){
            if(p1){
                dummy->next=p1;
                p1=p1->next;
                dummy = dummy->next;
            }
            if(p2){
                dummy->next=p2;
                p2=p2->next;
                dummy = dummy->next;
            }
        }
    }

    ListNode* midNode(ListNode* head){
        ListNode* fast = head;
        ListNode* slow =head;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        if(head==NULL) return NULL;
        ListNode* pre = NULL;
        ListNode* next =NULL;
        ListNode* cur = head;
        while(cur!=NULL){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
```