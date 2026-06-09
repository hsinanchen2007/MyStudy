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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head) return NULL; 

        vector<int> nums;

        while(head) 
        {
            nums.push_back(head->val);
            head=head->next;
        }        

        ListNode* res=new ListNode(-1),*_res=res;
        int n=nums.size();

        for(int i=n-k%n;i<2*n-k%n;i++)
        {
            res->next=new ListNode(nums[i%n]);
            res=res->next;
        }

        return _res->next;
    }
};
```