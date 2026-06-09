相似题目：[25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)
## 思路一：迭代
### 代码
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        int cnt = 1;
        ListNode *tail = head;
        ListNode *cur = head;
        while (tail != nullptr && cnt < 2) {
            tail = tail->next;
            ++cnt;
        }
        if (tail == nullptr) return head;
        ListNode *next = tail->next;
        tail->next = nullptr;
        ListNode *rev = reverse(cur);
        cur->next = swapPairs(next);
        return rev;
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr) return nullptr;
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
### 代码
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        int cnt = 0;
        ListNode *pre = head;
        while (pre != nullptr && cnt < 2) {
            pre = pre->next;
            ++cnt;
        }
        if (cnt == 2) {
            pre = swapPairs(pre);
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

