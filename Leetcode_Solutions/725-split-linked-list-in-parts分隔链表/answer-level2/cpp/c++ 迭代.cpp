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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len=0;
        auto p=root;
        while(p){
            p=p->next;
            ++len;
        }
        int mod=len/k;
        int remian=len%k;
        auto head=root;
        auto cur=root;
        int i=1;
        vector<ListNode*> res;
        while(cur){
            if(i++==mod+(remian>0?1:0)){
                res.push_back(head);
                head = cur->next;
                cur->next=NULL;
                cur=head;
                --remian;
                i=1;
            } else {
                cur=cur->next;
            }
        }
        i=res.size();
        while(i++<k){
            res.push_back(NULL);
        }
        return move(res);
    }
};
```
