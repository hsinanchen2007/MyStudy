```
class Solution {
public:
    struct cmp{bool operator()(ListNode* l1, ListNode* l2){return l1->val > l2->val;}};
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode* phead = new ListNode(0); ListNode* p = phead;
        if(lists.size() == 0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> MinHeap;
        for(int i = 0;i < lists.size();i++) if(lists[i] != nullptr)MinHeap.push(lists[i]);
        while(!MinHeap.empty()){
            p->next = MinHeap.top();p = p->next;
            if(MinHeap.top()->next != nullptr) MinHeap.push(MinHeap.top()->next);MinHeap.pop();
        }
        return phead->next;
    }   
};
```
