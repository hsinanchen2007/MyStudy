### 解题思路
标记小于给定值的链表末尾

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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* pHead = new ListNode(-1);
        pHead->next = head;
        ListNode* smallEnd = pHead;
        while(smallEnd->next != nullptr && smallEnd->next->val < x){
            smallEnd = smallEnd->next;
        }
        ListNode* pre = smallEnd;
        ListNode* cur = pre->next;
        while(cur != nullptr){
            if(cur->val >= x){
                pre = cur;
                cur = cur->next;
            }else{
                pre->next = cur->next;
                ListNode* tmp = smallEnd->next;
                smallEnd->next = cur;
                cur->next = tmp;
                smallEnd = cur;
                cur = pre->next;
            }
        }
        return pHead->next;
    }
};
```