### 解题思路
借助Vector容器进行解题

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
        ListNode* res=new ListNode(0);
        ListNode* head=res;
        vector<int> ves;
        for(int i = 0;i<lists.size();i++)
        {
            ListNode* cre=lists[i];
            while(lists[i]!=NULL)
            {
                ves.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(ves.begin(),ves.end());
        for(int i = 0;i<ves.size();i++)
        {
            ListNode *cre=new ListNode(ves[i]);
            head->next=cre;
            head=head->next;
        }
        head->next=NULL;
        res=res->next;
        return res;
    }
};
```