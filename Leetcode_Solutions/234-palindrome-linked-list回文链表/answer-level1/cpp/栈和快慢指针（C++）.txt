

## 使用栈

将链表元素放入栈内，如果遇见相同的就弹出，最后栈为空则为回文结构，O（n）,空间复杂度O（n）


```
#include <stack>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return true;
        }
        ListNode* cur = head;
        stack <int> s;
        while (cur){  
                s.push(cur->val);
                cur = cur->next;
            }
        cur = head;
        while (cur){
            if (s.top() == cur->val){
                s.pop();
            }
            cur = cur->next;
        }
        return s.empty();
    }
};
```
## 快慢指针

原地修改链表,额外空间复杂度O（1）

```
using namespace std;
class PalindromeList {
public:
    bool chkPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow->next);
        while (slow != NULL) {
            if (head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* here = head;
        while (here!=NULL) {
            ListNode* temp = here->next;
            here->next = pre;
            pre = here;
            here = temp;
        }
        return pre;
    }
};
```