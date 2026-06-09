```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct cmp{
     bool operator()(ListNode *p1,ListNode *p2){
         return p1->val>p2->val;
     }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, cmp> q;
        ListNode dummy(0);
        auto tail=&dummy;
        for(auto p:lists){
            if(p)q.push(p);
        }
        while(!q.empty()){
            auto top=q.top();
            q.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next)q.push(top->next);
        }
        return dummy.next;
    }
};
```
