写法可能麻烦了点，但是
时间复杂度:O(max(len(l1), len(l2)))
空间复杂度:O(1)
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
private:
    ListNode* sum(ListNode* l1, ListNode* l2) {
        ListNode* pre = nullptr;
        function<int(ListNode*)> getLength = [](ListNode* l1) {
            int res = 0;
            while (l1 != nullptr) res ++, l1 = l1->next;
            return res;
        };
        int len1 = getLength(l1), len2 = getLength(l2);
        if (len1 > len2) {
            int k = len1 - len2;
            while (k--) {
                ListNode* next = l1->next;
                ListNode* node = new ListNode(l1->val);
                node->next = pre;
                pre = node;
                l1 = next;
            }
        }
        else {
            int k = len2 - len1;
            while (k --) {
                ListNode* next = l2->next;
                ListNode* node = new ListNode(l2->val);
                node->next = pre;
                pre = node;
                l2 = next;
            }
        }
        while (l1 || l2) {
            int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            ListNode* node = new ListNode(val);
            node->next = pre;
            pre = node;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return pre;
    }
    ListNode* reverse(ListNode* s) {
        if (s == nullptr) return s;
        ListNode* pre = nullptr;
        int carry = 0;
        while (s) {
            ListNode* next = s->next;
            carry += s->val;
            s->val = carry % 10;
            carry /= 10;
            s->next = pre;
            pre = s;
            s = next;
        }
        while (carry != 0) {
            ListNode* node = new ListNode(carry % 10);
            node->next = pre;
            pre = node;
            carry /= 10;
        }
        return pre;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* s = sum(l1, l2);
        return reverse(s);
    }
};