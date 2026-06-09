## 思路一：迭代
从前向后一组一组进行反转。
### 代码
```c++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {              
        int cnt = 1;
        ListNode *pre = head;
        ListNode *tail = head;
        while (tail != nullptr && cnt < k) {
            tail = tail->next;
            ++cnt;
        }
        if (tail == nullptr) return head;        
        ListNode *next = tail->next;
        tail->next = nullptr;
        ListNode *rev = reverse(pre);
        if (next != nullptr) {
            pre->next = reverseKGroup(next, k);
        }
        return rev;   
    }
    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
```

## 思路二：递归
递归反转后面链表，然后反转当前链表节点。
### 代码
```c++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {                
        int cnt = 0;
        ListNode *pre = head;
        while (pre != nullptr && cnt < k) {
            pre = pre->next;
            ++cnt;
        }
        if (cnt == k) {
            pre = reverseKGroup(pre, k);
            while (cnt > 0) {
                ListNode *next = head->next;
                head->next = pre;
                pre = head;
                head = next;
                --cnt;
            }
            head = pre;
        }
        return head;
    }
};
```
