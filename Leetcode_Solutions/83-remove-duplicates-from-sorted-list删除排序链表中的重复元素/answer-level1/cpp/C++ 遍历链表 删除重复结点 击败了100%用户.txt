### 解题思路
用p结点存放整个链表，head用于遍历删除重复结点，注意head和head->next是否为NULL的判断，
注意重复结点有多个，当下一个next结点的val值不再等于head时才移动head结点继续下去。

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
        ListNode* p = head;
        if(head == NULL || head->next == NULL)  return head;
        while(head != NULL){
            if(head->next !=NULL && head->val == head->next->val){
                head->next = head->next->next;
            }
            else head = head->next;
        }
        return p;
    }
};
```