```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        stack<int> k;
        ListNode* p=head;
        while(p!=NULL){
            k.push(p->val);
            p=p->next;
        }
        p=head;
        while (!k.empty()){
            p->val=k.top();
            k.pop();
            p=p->next;
        }

        return head;
    }
};
```
