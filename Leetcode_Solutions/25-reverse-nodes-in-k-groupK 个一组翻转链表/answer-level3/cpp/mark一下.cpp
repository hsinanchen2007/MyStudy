![Screenshot from 2019-10-21 19-09-22.png](https://pic.leetcode-cn.com/59e0d0c499848da5aeb99b7c50f2064c82105f0eff93b57f444de6c4bce31007-Screenshot%20from%202019-10-21%2019-09-22.png)

    class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head)
                return NULL;
            ListNode* p = head;
            int count = 1;
            while(p->next)
            {
                p = p->next;
                count++;
            }
            //找出需要翻转最后分界点
            int n = (count/k);
            ListNode* last = new ListNode(0);
            last->next = head;
            ListNode* nextNode = last;
            for(int i=0; i<n; i++)
            {
                //逐个翻转
                nextNode = reverseKNode(nextNode->next, nextNode, k);
            }
            
            return last->next;
        }
    private:
        ListNode* reverseKNode(ListNode *head, ListNode* last, int k)
        {

            ListNode* lastin = last;
            ListNode* phead = head;
            ListNode* temp;
            
            for(int i=0; i<k; i++)
            {
                temp = phead->next;
                phead->next = lastin;
                lastin = phead;
                phead = temp;
            }
            head->next = phead;
            last->next = lastin;
        
            return head;
        }
    };