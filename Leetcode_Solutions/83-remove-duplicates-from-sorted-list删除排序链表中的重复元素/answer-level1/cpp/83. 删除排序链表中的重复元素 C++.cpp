### 解题思路
1.从链表头开始遍历整个链表，发现链表元素相同就将指向它的指针指向后一个元素，并将自己的指针至位NULL。
2.遍历完整个链表将链表头指针返回。

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
        ListNode *current = head;
        while(current != NULL && current->next != NULL){
            if(current->val == current->next->val){
                ListNode *node = current->next;
                current->next = node->next;
                node->next = NULL;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};
```