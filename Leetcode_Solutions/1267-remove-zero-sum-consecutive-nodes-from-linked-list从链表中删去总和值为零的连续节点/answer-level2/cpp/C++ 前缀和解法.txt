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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode empty(0);
        empty.next = head;
        ListNode* dummy = &empty;
        
        map<int, ListNode*> m;
        map<int, int> indices;
        vector<int> v;
        m[0] = dummy;
        v.push_back(0);
        indices[0] = 0;
        
        ListNode* node = head;
        int curr = 0;
        while (node != NULL) {
            curr += node->val;
            if (m.count(curr)) {
                m[curr]->next = node->next;
                for (int i = indices[curr] + 1; i < v.size(); ++i) {
                    m.erase(v[i]);
                }
            } else {
                m[curr] = node;
                v.push_back(curr);
                indices[curr] = v.size() - 1;
            }
            node = node->next;
        }
        return dummy->next;
    }
};
```

![image.png](https://pic.leetcode-cn.com/fcf71d215c704b3813af5473b575cfd6122daac92ee085039ada3ce1b16bef2b-image.png)
