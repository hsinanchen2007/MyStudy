执行用时 :52 ms, 在所有 cpp 提交中击败了98.62%的用户
```
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !(head->next) || !(head->next->next))
            return;
        vector<ListNode*> h;
        ListNode *temp = head;
        while(temp){
            h.push_back(temp);
            temp = temp->next;
        }
        int lens = h.size(), i;
        for(i = 0; i < lens/2; i++){
            h[i]->next = h[lens-i-1];
            h[lens-i-1]->next = h[i+1];
        }
        h[i]->next = NULL;
        return;
    }
};
```
