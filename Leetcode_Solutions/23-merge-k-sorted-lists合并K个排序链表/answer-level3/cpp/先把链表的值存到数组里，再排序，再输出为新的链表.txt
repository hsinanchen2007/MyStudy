### 解题思路


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
        vector<int> res;
        for(int i=0;i<lists.size();i++)
        {
            ListNode * tmp = lists[i];
            while(tmp != NULL)
            {
                res.push_back(tmp->val);
                tmp =  tmp->next;
            }
        }
        sort(res.begin(),res.end());
       ListNode * ans = new ListNode(0);
       ListNode * frist = ans;
       for(int i =0;i<res.size();i++)
       {
           frist->next = new ListNode(res[i]);
           frist = frist->next;
       }
      ans = ans ->next;
      return ans;
    }
};
```