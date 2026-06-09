自定义ListNode*的比较函数，使得ListNode*按照val的大小排序，priority_queue在push时排序。

```
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* resTmp = res;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()) {
            resTmp->next = new ListNode(pq.top()->val);
            resTmp = resTmp->next;
            ListNode* topNext = pq.top()->next;
            pq.pop();
            if(topNext != NULL) {
                pq.push(topNext);
            }
        }
        return res->next;
    }
};
```