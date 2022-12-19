## 思路
### 代码
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        if (p == nullptr || p->next == nullptr) {
            return head;
        }
        ListNode *pre = head;
        p = p->next;
        while (p != nullptr) {
            if (p->val == pre->val) {
                ListNode *next = p->next;
                pre->next = next;
                p = next;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
```

#### 简化代码
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        if (p == nullptr || p->next == nullptr) {
            return head;
        }
        while (p != nullptr && p->next != nullptr) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
```

