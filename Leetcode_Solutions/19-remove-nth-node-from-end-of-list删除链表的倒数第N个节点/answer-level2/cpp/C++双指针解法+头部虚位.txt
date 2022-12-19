### 解题思路
双指针解法

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || (head->next==NULL && n==1)) return NULL;
        ListNode *res=new ListNode(NULL);
        res->next=head;
        ListNode *start=res,*end=res;
        int diff=0;
        while (end!=NULL){
            if (diff<n+1) {
                end=end->next;
                diff++;
                continue;
            }
            start=start->next;
            end=end->next;
        }
        start->next=start->next->next;
        return res->next;
    }
};
```