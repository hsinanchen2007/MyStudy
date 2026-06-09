第一遍扫描得到长度n，然后把vector空间开出来，第二遍扫描直接往里写，不要对vector做插入操作。

```c++
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
    vector<int> reversePrint(ListNode* head) {
        int n = 0;
        for(ListNode* t=head;t;t=t->next) {
            n++;
        }
        vector<int> ans(n);
        int j = 0;
        for(ListNode* t=head;t;t=t->next,j++) {
            ans[n-1-j] = t->val;
        }
        return ans;
    }
};
```
