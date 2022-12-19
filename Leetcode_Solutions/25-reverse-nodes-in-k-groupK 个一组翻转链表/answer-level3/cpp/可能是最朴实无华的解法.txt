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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==nullptr||head->next==nullptr)
            return head;
        auto *p = new ListNode(-1);
        p->next = head;
        vector<ListNode *> vP;
        ListNode *q = p;
        while (q->next != nullptr) {
            q = q->next;
            vP.push_back(q);
        }
        int d = vP.size() / k;
        if(d==0)return head;
        for (int i = 0; i < d * k; i++) {
            vP[i]->next = nullptr;
        }
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < k - 1; j++) {
                vP[i * k + k - j - 1]->next = vP[i * k + k - j - 2];
            }
        }
        p->next = vP[k-1];
        for (int i = 0; i < d-1; i++) {
            vP[i * k]->next = vP[(i + 2) * k-1];
        }
        if(vP.size()>d*k){
            vP[(d-1)*k]->next=vP[d*k];
        }
        return p->next;
    }
};
```
