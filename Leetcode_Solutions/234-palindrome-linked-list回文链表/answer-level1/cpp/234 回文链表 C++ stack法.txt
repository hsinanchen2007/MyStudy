### 解题思路
1.将所有元素入栈
2.顺序遍历链表，看stack栈顶元素与遍历指针指向链表元素是否一致

注意
1.为什么不用stack判断合法括号类似的方法，即一遍进出栈
答：难以避免11223344这类场景
2.为什么不先reverse再判断两个链表是否相等
答：多数reverse都是原地反转，如果copy一个链表再反转是可以的

### 代码

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
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        stack<int> s;
        ListNode* cur = head;
        while (cur) {
            s.push(cur->val);
            cur = cur->next;
        }
        while (head) {
            if (s.top() == head->val) s.pop();
            else return false;
            head = head->next;
        }
        return s.empty();
    }
};
```