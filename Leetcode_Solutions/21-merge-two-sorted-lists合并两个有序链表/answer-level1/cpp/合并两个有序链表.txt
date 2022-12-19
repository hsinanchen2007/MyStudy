### 解题思路
先将两个链表的数值压进去一个最小优先队列，然后输出优先队列到一个新的链表即可。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        priority_queue<int,vector<int>, greater<int>> pq;
        while(l1 != NULL){
            pq.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2 != NULL){
            pq.push(l2 -> val);
            l2 = l2 -> next;
        }
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        while(!pq.empty()){
            tmp -> next = new ListNode(pq.top());
            pq.pop();
            tmp = tmp -> next;
        }
        return res -> next;
    }
};
```