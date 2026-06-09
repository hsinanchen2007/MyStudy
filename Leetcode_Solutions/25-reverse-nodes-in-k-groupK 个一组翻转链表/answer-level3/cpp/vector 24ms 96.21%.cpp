
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> relist;
        ListNode* startnode=head;
        int length=0;
        while(startnode){
            relist.push_back(startnode);
            length++;
            startnode=startnode->next;
        }
        if(length<k) return head;
        length=relist.size();
        int start=0;
        while(start+k<=length){
            reverse(relist.begin()+start,relist.begin()+start+k);
            start+=k;
        }
        int i;
        for( i=0;i<length-1;i++){
            relist[i]->next=relist[i+1];
        }
        relist[i]->next=NULL;
        return relist[0];
    }
};