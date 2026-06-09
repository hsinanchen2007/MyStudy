class Solution {
public:
    ListNode* middleNode(ListNode *head) {
        ListNode * fast,*slow;
        fast = slow = head;
        int cnt = 0;
        while(fast)
        {
            fast = fast->next;
            cnt++;
            if(cnt == 2)
            {
                slow = slow->next;
                cnt=0;
            }
        }
        return slow;
    }
};