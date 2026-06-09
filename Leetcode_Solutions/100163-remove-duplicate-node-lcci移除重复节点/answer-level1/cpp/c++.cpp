### 解题思路
第一反应只能想出这样麻烦的解法了

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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* result=new ListNode(0);
        ListNode* r=result;
        unordered_map<int,int> map;
        vector<int> v;
        while(head)
        {
            map[head->val]++;
            if(map[head->val]==1)
            {
                v.push_back(head->val);
            }
            head=head->next;
        }
        for(int i=0;i<v.size();i++)
        {
                ListNode* res=new ListNode(v[i]);
                r->next=res;
                r=res;
        }
        return result->next;
    }
};
```