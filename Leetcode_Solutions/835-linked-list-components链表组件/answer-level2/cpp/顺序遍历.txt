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
        int ans=0;
        int flag=false;
        unordered_set<int> s;
        for(auto a:G){
            s.insert(a);
        }
        ListNode* temp=head;
        while(temp!=NULL){
            if(s.count(temp->val)){
                if(!flag){
                    ++ans;
                    flag=true;
                }
            }
            else{
                flag=false;
            }
            temp=temp->next;
        }
        return ans;
    }
};
```
