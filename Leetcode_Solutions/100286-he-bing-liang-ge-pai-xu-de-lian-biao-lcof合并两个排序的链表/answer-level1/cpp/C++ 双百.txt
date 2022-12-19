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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(-1);
        ListNode* ret = p;
        while(l1 && l2){
            if(l1 -> val <= l2 -> val){
                p -> next = l1;
                l1 = l1 -> next;
            }
            else{
                p -> next = l2;
                l2 = l2 -> next;
            }
            p = p -> next;
        }
        p -> next = l1 ? l1 : l2;
        return ret -> next;
    }
};
```