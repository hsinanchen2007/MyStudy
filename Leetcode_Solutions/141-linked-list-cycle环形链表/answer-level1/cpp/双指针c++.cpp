### 解题思路
双指针，快的每次走两步，若是有环，快指针会追上慢指针

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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return false;
        ListNode * pSlow=head->next;
        ListNode * pFast=pSlow->next;
        bool flag=false;
        while(pFast!=NULL&&pSlow!=NULL)
        {
            if(pFast==pSlow)
            {
                flag=true;
                break;
            }
            pSlow=pSlow->next;
            pFast=pFast->next;
            if(pFast!=NULL)
            pFast=pFast->next;
        }
        return flag;
    }
};
```