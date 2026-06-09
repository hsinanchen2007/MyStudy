使用自定义的排序方法，可以稍微简化整个处理。个人认为还是比较清晰的。

```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto my_comp = [](const ListNode* a, const ListNode* b){ return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(my_comp)> queue(my_comp);
        for(ListNode* head: lists) {
            if(head != nullptr)
                queue.push(head);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!queue.empty()) {
            ListNode* n = queue.top();
            queue.pop();
            if(n->next != nullptr)
                queue.push(n->next);
            curr->next = n;
            curr = curr->next;
        }
        return dummy->next;
    }
};
```
