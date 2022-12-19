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
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *pre=head;
        vector<ListNode*> list;
        
        while(pre)
        {
            int i=list.size()-1,j=i+1;
            list.push_back(pre);

            while(pre->next && pre->next->val==pre->val) 
            {
                list.push_back(pre->next);
                pre=pre->next,j++;
            }

            if(j>i+1)
            {
                if(i>=0) list[i]->next=pre->next;
                else head=pre->next;
                
                pre=pre->next;
                for(int d=i+1;d<=j;d++) delete list[d];
                for(int p=i+1;p<=j;p++) list.pop_back();
            }
            else pre=pre->next;
        }  

        return head;
    }
};
```