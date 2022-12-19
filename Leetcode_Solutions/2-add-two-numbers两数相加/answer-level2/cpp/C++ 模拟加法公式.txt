加法公式
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* ans = new ListNode((l1->val+l2->val)%10);
        flag = (l1->val+l2->val) / 10;
        ListNode* tmp = ans;
        ListNode* t1 = l1->next;
        ListNode* t2 = l2->next;
        while(t1!=NULL && t2!=NULL){
            int sum = t1->val + t2->val + flag;
            tmp->next =new ListNode(sum%10);
            tmp = tmp->next;
            flag = sum / 10;
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1==NULL){
            while(t2!=NULL){
                int sum = t2->val + flag;
                tmp->next = new ListNode(sum%10);
                tmp = tmp->next;
                flag = sum / 10;
                t2 = t2->next;
            }
        }
        else if(t2==NULL){
            while(t1!=NULL){
                int sum = t1->val + flag;
                tmp->next = new ListNode(sum%10);
                tmp = tmp->next;
                flag = sum / 10;
                t1 = t1->next;
            }
        }
        if(flag==1){
            tmp->next = new ListNode(1);
            tmp = tmp->next;
        }
        return ans;
    }
};
