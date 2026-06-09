1. c++的优先队列支持自定义比较函数，比python好用；代码看起来简单多了


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include <queue>

struct cmp {
    bool operator ()(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto l : lists) {
            if(l != NULL) {
                q.push(l);
            }
        }
        while(!q.empty()) {
            ListNode* top = q.top();
            q.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next != NULL) {
                q.push(top->next);
            }
        }

        return head->next;
    }
};