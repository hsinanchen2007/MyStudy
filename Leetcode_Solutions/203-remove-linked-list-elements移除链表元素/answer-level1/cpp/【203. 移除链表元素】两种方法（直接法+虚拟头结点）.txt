## 思路一：直接法
### 代码
```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head;
        if (cur == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;        
        while (cur) {
            if (cur->val == val) {
                cur = cur->next;
                if (pre == nullptr) {
                    head = cur;
                } else {
                    pre->next = cur;
                }
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
```

## 思路二：虚拟头结点
### 代码
```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {       
        if (head == nullptr) {
            return head;
        }
        ListNode *pHead = new ListNode(0);
        pHead->next = head;
        ListNode *pre = pHead;        
        ListNode *cur = head;
        while (cur) {
            if (cur->val == val) {
                cur = cur->next;
                pre->next = cur;                
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return pHead->next;
    }
};
```

