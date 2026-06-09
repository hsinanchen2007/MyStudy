### 解题思路
遍历一遍同时把值压入栈中，利用栈先进后出的特性，第二次遍历时同时弹栈。

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
        ListNode * p = head;
        stack<int> s;
        while(p){
            s.push(p->val);
            p = p->next;
        }
        while(head){
            if(head->val != s.top()) return false;
            head = head->next;
            s.pop();
        }
        return true;
    }
};
```