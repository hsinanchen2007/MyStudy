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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *odd = head,*even = head->next,*p = even;
        while(odd->next && even->next){
            odd->next = even->next;
            odd = odd->next;
            if(odd->next){
                even->next = odd->next;
                even = even->next;
            }
        }
        odd->next = p;
        even->next = NULL;
        return head;
    }
};
```