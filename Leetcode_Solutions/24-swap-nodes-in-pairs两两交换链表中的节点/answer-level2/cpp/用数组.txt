先用数组保存每个节点，然后在数组取出重组时两两翻转。
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<ListNode* > pr;
        while(head != NULL){
            pr.push_back(head);
            head = head->next;
        } 
        ListNode* p;
        if(pr.size() % 2 == 0){
            for(int i = 0; i < pr.size(); i += 2){
                p = pr[i + 1]->next;
                pr[i + 1]->next = pr[i];
                pr[i]->next = p;
                if(i > 0){
                    pr[i - 2]->next = pr[i + 1];
                }
            }
            pr[pr.size() - 2]->next = NULL;
        }
        else{
            for(int i = 0; i < pr.size() - 1; i += 2){
                p = pr[i + 1]->next;
                pr[i + 1]->next = pr[i];
                pr[i]->next = p;
                if(i > 0){
                    pr[i - 2]->next = pr[i + 1];
                }
            }
            pr[pr.size() - 3]->next = pr[pr.size() - 1];
            pr[pr.size() - 1]->next = NULL;
        }
        return pr[1];
    }
};