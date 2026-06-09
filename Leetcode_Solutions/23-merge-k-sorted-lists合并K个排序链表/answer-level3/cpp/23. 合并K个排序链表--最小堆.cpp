### 解题思路
执行用时 44 ms, 在所有 C++ 提交中击败了39.76%的用户

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
    struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp > q;
        for(auto list: lists){
            if(list != NULL){
                q.push(list);
            }
        }
        ListNode *head = new ListNode(-1);
        ListNode *fist_node = head;
        while(!q.empty()){
            ListNode* tmp = q.top();
            q.pop();
            if(tmp->next != NULL) q.push(tmp->next);
            head->next = tmp;
            head = tmp;
        }
        head->next = NULL;
        return fist_node->next;
    }
};
```