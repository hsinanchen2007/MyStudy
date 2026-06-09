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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vec;
        for(int i=0;i<lists.size();i++)
        {
            ListNode *p=lists[i];
            while(p!=NULL)
            {
                vec.push_back(p->val);
                p=p->next;
            }
        }
        if(vec.size()==0)
            return NULL;
        sort(vec.begin(),vec.end());
        ListNode *head,*end;
        for(int i=0;i<vec.size();i++)
        {
            ListNode *p=new ListNode(vec[i]);
            if(i==0)
            {
                head=p;end=p;continue;
            }
            end->next=p;
            end=end->next;

        }

        return head;


    }
};
```