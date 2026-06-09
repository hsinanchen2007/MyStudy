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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int,bool> m;
        for(auto g:G)m[g]=true;
        int res=0;
        auto p=head;
        while(p){
            if(m.count(p->val)){
                ++res;
                while(p&&m.count(p->val))p=p->next;
            }else{
                p=p->next;
            }
        }
        return res;
    }
};
```
