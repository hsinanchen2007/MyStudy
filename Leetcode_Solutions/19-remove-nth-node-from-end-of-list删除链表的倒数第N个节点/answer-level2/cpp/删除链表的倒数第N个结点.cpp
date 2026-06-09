### 解题思路
双指针法。假设总共有M个数，删除倒数第N个数，则令一个指针（fast）从头先遍历N个数，再令另一个指针（slow）和这个指针（fast）一起遍历直到fast指向空，则两个指针都遍历了M-N个数，slow停留在被删除结点的前驱结点，直接删除即可。
时间复杂度为O（N）。dummy为头节点，不保存数。
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
        ListNode* dummy = new ListNode(NULL);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for(int i = 0; i <= n; i++){
            fast = fast->next;
        }
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
```