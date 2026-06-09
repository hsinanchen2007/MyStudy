## 思路一：直接法
### 代码
```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *cur = head;
        ListNode *pre = nullptr;        
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->next->val == cur->val) {
                while (cur->next != nullptr && cur->next->val == cur->val) {
                    cur = cur->next;
                }
                cur = cur->next;
                //pre为空，表示头节点重复
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

## 思路二：虚拟头节点
为了便于删除原链表第一个节点就出现重复，新增一个虚拟节点并设置pre指针指向虚拟节点。
### 代码
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *cur = newHead->next;
        ListNode *pre = newHead;
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->next->val == cur->val) {
                while (cur->next != nullptr && cur->next->val == cur->val) {
                    cur = cur->next;
                }
                cur = cur->next;
                pre->next = cur;                
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};
```