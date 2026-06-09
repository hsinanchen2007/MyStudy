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
        ListNode dummy(0);
        ListNode* p=head;
        ListNode* pre=&dummy;
        while(p!=nullptr&&p->next!=nullptr)
        {
            st.push(p);
            st.push(p->next);
            p=p->next->next;
            
            ListNode* temp=st.top();
            pre->next=temp;
            pre=pre->next;
            st.pop();
            
            temp=st.top();
            pre->next=temp;
            pre=pre->next;
            st.pop();
            
           
        }
        if(p)
            pre->next=p;
        else
            pre->next=nullptr;
        return dummy.next;
        
    }
    stack<ListNode*> st;
};