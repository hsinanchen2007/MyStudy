### 解题思路

堆栈的数据结构，可以很好的利用堆栈后进先出的规则。

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
    // 利用栈后进先出的规则
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        while(head) {
            //cout << head->val << endl;
            s.push(head->val);
            head = head->next;
        }
        vector<int> res;
        
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};
```