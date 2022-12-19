### 解题思路
此处撰写解题思路

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

  vector<int> nextLargerNodes(ListNode* head) {
    std::stack<std::pair<int, int>> ST; // val:idx
    vector<int> ans(10000, 0);
    int seq = 0;
    while (head) {
      while (!ST.empty() && ST.top().first < head->val) {
        ans[ST.top().second] = head->val;
        ST.pop();
      }
      ST.push({head->val, seq});
      ++seq, head = head->next;
    }
    ans.resize(seq);
    return ans;     
  }
};
```