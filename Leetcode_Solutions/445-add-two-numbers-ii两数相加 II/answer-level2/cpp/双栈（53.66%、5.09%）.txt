# Update on 2020-03-18-9:52

- 执行用时 :32 ms, 在所有 C++ 提交中击败了53.66%的用户

- 内存消耗 :74.5 MB, 在所有 C++ 提交中击败了5.09%的用户

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for (ListNode* p1 = l1; p1 != nullptr; p1 = p1->next) {
            s1.push(p1->val);
        }
        for (ListNode* p2 = l2; p2 != nullptr; p2 = p2->next) {
            s2.push(p2->val);
        }
        int n1 = 0, n2 = 0, Sum = 0, carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = NULL;
        while (!s1.empty() || !s2.empty() || carry/*easy to forget*/) {
            if (s1.empty()) {
                n1 = 0;
            }
            else {
                n1 = s1.top();
                s1.pop();
            }
            if (s2.empty()) {
                n2 = 0;
            }
            else {
                n2 = s2.top();
                s2.pop();
            }
            Sum = n1 + n2 + carry;
            // 头插法建表
            temp = new ListNode(Sum % 10);
            temp->next = dummy->next;
            dummy->next = temp;
            carry = Sum / 10;
        }
        // 释放 dummy 防止内存泄露
        ListNode* res = dummy->next;
        delete dummy;        
        return res;
    }
};

```

# Update on 2020-03-18-9:37

- 执行用时 :44 ms, 在所有 C++ 提交中击败了20.91%的用户

- 内存消耗 :74.3 MB, 在所有 C++ 提交中击败了5.09%的用户

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for (ListNode* p1 = l1; p1 != nullptr; p1 = p1->next) {
            s1.push(p1->val);
        }
        for (ListNode* p2 = l2; p2 != nullptr; p2 = p2->next) {
            s2.push(p2->val);
        }
        ListNode* res = new ListNode(-1);
        int carry = 0;
        while (!s1.empty() && !s2.empty()) {
            int a = s1.top();
            s1.pop();
            int b = s2.top();
            s2.pop();
            ListNode* temp = new ListNode((a + b + carry) % 10);
            temp->next = res->next;
            res->next = temp;
            carry = (a + b + carry) / 10;
        }
        while (!s1.empty() && s2.empty()) {
            int a = s1.top();
            s1.pop();
            ListNode* temp = new ListNode((a + carry) % 10);
            temp->next = res->next;
            res->next = temp;
            carry = (a + carry) / 10;
        }
        while (s1.empty() && !s2.empty()) {
            int b = s2.top();
            s2.pop();
            ListNode* temp = new ListNode((b + carry) % 10);
            temp->next = res->next;
            res->next = temp;
            carry = (b + carry) / 10;
        }
        if (carry) {
            ListNode* temp = new ListNode(carry);
            temp->next = res->next;
            res->next = temp;
        }
        return res->next;
    }
};
```
