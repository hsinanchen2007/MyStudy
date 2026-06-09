两种方法：
递归
递归就是每次都只做一点点，剩下的让后面的接着做
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* dfs(ListNode* left, ListNode* right)
    {
        if(right)
        {
            auto nxt = right->next;
            right->next = left;
            left = right;
            right = nxt;
            return dfs(left, right);
        }
        else
            return left;
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = nullptr;
        auto left = dummy, right = head;
        return dfs(left,right);
    }
};

```
```
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        auto pt = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return pt;
    }
};
```


循环
```
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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = nullptr;
        auto left = dummy, right = head;
        while(right)
        {
            auto nxt = right->next;
            right->next = left;
            left = right;
            right = nxt;
        }
        return left;
    }
};
```
使用栈

```
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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stk;
        auto pt = head;
        while(pt)
        {
            stk.push(pt);
            pt = pt->next;
        }
        auto dummy = new ListNode(0);
        pt = dummy;
        while(stk.size())
        {
            pt->next = stk.top();
            stk.pop();
            pt = pt->next;
        }
        pt->next = nullptr;
        return dummy->next;
    }
};
```
