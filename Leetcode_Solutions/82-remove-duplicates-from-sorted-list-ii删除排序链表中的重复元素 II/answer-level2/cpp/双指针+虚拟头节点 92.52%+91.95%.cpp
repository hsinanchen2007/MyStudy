### 解题思路
开头添加虚拟头节点解决链表头有重复的情况，双指针遍历

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
        ListNode* now = dummy;
        while(now != NULL){
            if(now->next!=NULL && now->next->next!=NULL && now->next->val ==                now->next->next->val){
                int tmp = now->next->val;
                ListNode* after = now->next->next->next;
                while(after!=NULL && after->val == tmp ){
                    after = after->next;
                }
                now->next = after;
            }
            else now = now->next;
        }
        return dummy->next;
    }
};
```