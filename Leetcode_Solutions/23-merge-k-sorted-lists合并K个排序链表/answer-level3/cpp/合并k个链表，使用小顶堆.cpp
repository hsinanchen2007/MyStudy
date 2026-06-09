### 解题思路
将k个链表的头指针加入小顶堆(注意要自己定义比较函数)，取出堆顶后，若后续next还有元素，则重新加入堆，直到堆为空为止

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        auto cmp = [](ListNode* a,ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> h(cmp);
        for(auto* l:lists)
            if(l) h.push(l);
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(!h.empty()){
            ListNode* p = h.top();
            h.pop();
            if(p->next)
                h.push(p->next);
            tail->next = p;
            tail = tail->next;
            tail->next = NULL;
        }
        return dummy->next;
    }
    
};
```