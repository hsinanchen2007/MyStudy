```
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        ListNode* tail = nullptr;
        int i = 0;
        while(node){
            if(i==n)break;
            ++i;
            node = node->next;
        }
        // cout<<node->val<<endl;
        cout<<i<<n;
        if(i==n && !node) return head->next; //删的是头结点
        if(i!=n) return head; // n>size()
        
        tail = head;
        while(node->next){
            ++i;
            tail = tail->next;
            node = node->next;
        }
        // cout<<tail->val;
        tail->next = tail->next->next;
        
        return head;
    }
};
```