```
class Solution {
public:

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *re = l1, *pg;
        int jw = 0;
        while (1) {

            l1->val += (l2 == NULL ? 0 : l2->val) + jw;
            if (l1->val >= 10) {
                jw = 1;
                l1->val -= 10;
            }
            else jw = 0;

            if (l2 != NULL) l2 = l2->next;

            pg = l1;
            l1 = l1->next;
            if (l1 == NULL) break;
        }
        if (l2 != NULL || jw != 0) {
            if (l2 == NULL && jw == 1) { pg->next = new ListNode(1); }
            else {
                pg->next = l2;
                while (l2 != NULL) {
                    l2->val += jw;
                    if (l2->val >= 10) {
                        jw = 1;
                        l2->val -= 10;
                    }
                    else break;
                    pg=l2;
                    l2 = l2->next;
                    if(l2==NULL && jw==1) pg->next=new ListNode(1);
                }
            }
        }

        return re;
    }
};
```
