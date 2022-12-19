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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pre=head;
        int len=0;
        while(pre){
            len++;
            pre=pre->next;
        }
        int i=len-k;
        while(i--){
            head=head->next;
        }
        return head;
    }
};
```