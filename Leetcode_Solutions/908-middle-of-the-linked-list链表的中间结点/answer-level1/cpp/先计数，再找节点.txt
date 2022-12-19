两次遍历
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
    ListNode* middleNode(ListNode* head) {
        int cnt=1;
        ListNode* tmp=head;
        while(tmp->next!=NULL){
            ++cnt;
            tmp=tmp->next;
        }
        tmp=head;
        for(int i=0;i<cnt/2;++i){
            tmp=tmp->next;
        }
        return tmp;
    }
};
```
