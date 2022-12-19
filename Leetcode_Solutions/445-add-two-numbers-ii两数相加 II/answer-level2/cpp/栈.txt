### 解题思路
此处撰写解题思路

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode *> l1stack, l2stack;
        stack<ListNode *> lstack;  //存储相加后的链表
        ListNode *temp1 = l1, *temp2 = l2;
        while(temp1)
        {
            l1stack.push(temp1);
            temp1 = temp1->next;
        }
        while(temp2)
        {
            l2stack.push(temp2);
            temp2 = temp2->next;
        }
        int digit = 0;  //判断是否有进位
        while(!l1stack.empty() || !l2stack.empty() || digit!=0)  //注意这个循环条件
        {
            //循环退出的条件是所有栈都空且无进位
            int val1, val2;
            if(l1stack.empty())val1 = 0;
            else
            {
                val1 = (l1stack.top())->val;
                l1stack.pop();
            }
            if(l2stack.empty())val2 = 0;
            else
            {
                val2 = (l2stack.top())->val;
                l2stack.pop();
            }
            int val = val1 + val2 + digit;
            ListNode *node = new ListNode(val % 10);
            lstack.push(node);
            digit = val / 10;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while(!lstack.empty())
        {
            temp->next = lstack.top();
            temp = temp->next;
            lstack.pop();
        }
        return dummy->next;
    }
};
```