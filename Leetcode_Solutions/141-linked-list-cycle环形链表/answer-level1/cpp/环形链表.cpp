```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```
- step1: 如果链表为空或只有一个结点，则必定不成环，返回false
- step2: 定义快慢双指针，slow每次移动一个结点，fast每次移动两个结点
- step3: 假设链表成环，则快指针必定在某个时刻与慢指针指向通过对象，退出循环；如果快指针为空，或者快指针指向结点的下个结点为空（因为每次移动两个结点，所以需要判断当前和下一个结点），则返回false
- step4: 返回true

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;
            } else {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        
        return true;
    }
};
```