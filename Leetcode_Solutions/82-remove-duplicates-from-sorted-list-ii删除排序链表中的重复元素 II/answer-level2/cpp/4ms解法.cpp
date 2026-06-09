### 解题思路
迭代 iter指向当前有效的节点，然后寻找下一个有效节点，如果当前节点的下一个节点和下下个节点值不一样，则下一个节点也是有效的，反之则寻找下一个不重复 的节点。

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* iter = dummy;
        while(iter){
            if(iter->next==NULL || iter->next->next==NULL){
                break;
            } else if(iter->next->val != iter->next->next->val){
                iter = iter->next;
            } else {
                ListNode* nextiter = iter->next->next->next;
                while(nextiter && nextiter->val == iter->next->val){
                    nextiter = nextiter->next;
                }
                iter->next = nextiter;
            }
        }
        return dummy->next;
    }
};
```