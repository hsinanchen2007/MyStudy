使用mutimap代替优先队列，mutimap会自动对key从小到大排序，可以免去编写比较函数的麻烦。
```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> headMap;
        for (ListNode* l : lists)
        {
            if (l != NULL)
                headMap.insert(pair<int, ListNode*>(l->val, l));
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!headMap.empty())
        {
            multimap<int, ListNode*>::iterator iterator = headMap.begin();
            tail->next = iterator->second;
            tail = tail->next;
            if (iterator->second->next != NULL) headMap.insert(pair<int, ListNode*>(iterator->second->next->val, iterator->second->next));
            headMap.erase(iterator);
        }
        tail->next = NULL;
        return dummy.next;
    }
};
```