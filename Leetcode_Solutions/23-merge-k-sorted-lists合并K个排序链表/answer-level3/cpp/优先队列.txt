### 解题思路
最小堆构建优先队列，维护初始大小为k的优先队列

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
        int k = lists.size();
        ListNode* dummyHead = new ListNode(0);
        ListNode* tmp = dummyHead;
        
        // 数值，node
        priority_queue< pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
        for(int i=0; i<k; i++){
            if(lists[i] != NULL)
                pq.push(make_pair(lists[i]->val, lists[i]));
        }
        while( !pq.empty() ){
            ListNode* next = pq.top().second->next;
            pq.top().second->next = NULL;

            tmp->next = pq.top().second;
            tmp = tmp->next;
            pq.pop();

            if(next!=NULL){
                pq.push( make_pair(next->val, next) );
            }
        }
        return dummyHead->next;
    }
};
```