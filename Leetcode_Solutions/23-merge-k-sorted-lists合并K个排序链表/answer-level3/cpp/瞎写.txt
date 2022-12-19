### 解题思路
被空链表卡了一会。。

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
        vector<int>tol_num;
        for(ListNode* ptr:lists){
            ListNode*p = ptr;
            while(p){
                tol_num.push_back(p->val);
                p = p -> next;
            }
        }
        if(not tol_num.size())return NULL;
        sort(tol_num.begin(), tol_num.end());
        ListNode*res = new ListNode(tol_num[0]);
        ListNode*cur = res;
        int tol_len = tol_num.size();
        for(int i=1;i<tol_len;++i){
            cur->next = new ListNode(tol_num[i]);
            cur = cur->next;
        }
        return res;
    }
};
```