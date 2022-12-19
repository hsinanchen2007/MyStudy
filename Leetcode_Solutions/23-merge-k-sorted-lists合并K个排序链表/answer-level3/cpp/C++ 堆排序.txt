### 解题思路
利用堆排序每次取出最小值加入新链表即可

### 代码

```cpp
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
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(0);
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;

        for (auto& ptr : lists) {
            if (ptr != nullptr) heap.push(ptr);
        }

        ListNode* p = dummyHead;
        while (!heap.empty()) {
            ListNode* cur = heap.top(); heap.pop();
            ListNode* next = cur->next;
            p->next = cur;
            p = p->next;
            if (next != nullptr) heap.push(next);
        }

        p->next = nullptr;
        return dummyHead->next;
    }
};
```