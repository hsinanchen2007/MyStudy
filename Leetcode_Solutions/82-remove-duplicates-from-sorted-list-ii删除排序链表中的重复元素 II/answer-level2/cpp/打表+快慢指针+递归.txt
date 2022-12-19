## 方法一：打表

- 执行用时 :28 ms, 在所有 C++ 提交中击败了5.84%的用户
- 内存消耗 :7.9 MB, 在所有 C++ 提交中击败了100.00%的用户

开始没有注意到 `sorted linked list`，所以想出来的方法，可以去除**任意链表**里的重复元素。

```c++
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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;
        for (ListNode* p = head; p; p = p->next) {
            m[p->val]++;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy->next;
        ListNode* prev = dummy;
        while (p) {
            if (m[p->val] > 1) {
                ListNode* temp = p;
                prev->next = p->next;
                p = p->next;
                delete(temp);
            }
            else {
                prev = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
```

## 方法二：快慢指针

- 执行用时 :8 ms, 在所有 C++ 提交中击败了85.36%的用户
- 内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户

slow 之前（包含 slow）的元素均满足要求，fast 扫描连续重复元素，remove 这部分元素即可。（注意释放结点，防止内存泄漏）

```c++
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy->next;
        while (fast) {
            if (fast->next && fast->val == fast->next->val) {
                int VAL = fast->val;
                ListNode* temp = nullptr;
                while (fast && fast->val == VAL) {
                    temp = fast;
                    fast = fast->next;
                    delete(temp);
                }
                slow->next = fast;
            }
            else {
                slow = slow->next;
                fast = slow->next;
            }
        }
        return dummy->next;
    }
};
```

## 方法三：递归

- 执行用时 :8 ms, 在所有 C++ 提交中击败了85.36%的用户
- 内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        if (head->next && head->next->val == head->val) {
            int VAL = head->val;
            ListNode* temp = nullptr;
            while (head && head->val == VAL) {
                temp = head;
                head = head->next;
                delete(temp);
            }
            return deleteDuplicates(head);
        }
        else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};
```

