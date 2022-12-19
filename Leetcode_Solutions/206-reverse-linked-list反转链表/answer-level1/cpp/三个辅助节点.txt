### 解题思路
三个节点，first记录已经翻转的链表头，middle是需要翻转的节点，later是middle的下一个作为辅助。当然存在各种边界条件，不是很好的实现。

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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }else if(!head->next->next){
            ListNode* first = head;
            ListNode* later = head->next;
            later->next = first;
            first->next = NULL;
            return later;
        }

        ListNode* first = head;
        ListNode* middle = head->next;
        ListNode* later = head->next->next;

        first->next = NULL;
        while(later){   
            middle->next = first;
            first = middle;
            middle = later;
            later = later->next;
        }
        middle->next = first;
        return middle;
    }
};
```