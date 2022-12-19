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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* pre = head;   //让这个取出原链表的每个节点
        ListNode* rear = NULL;  //说是尾部，其实也就是头部的功能，插在pre取出的节点的后面，之后rear又重新赋值为头部。最后return rear就行。
        while(head)
        {
            head = head->next;
            pre->next = rear;
            rear = pre;
            pre = head;
        }
        return rear;


        // 这个方法吃力不讨好。 16ms， 20%
        // if(head == NULL)
        //     return NULL;
        // stack<ListNode*> node_stack;
        // while(head)
        // {
        //     node_stack.push(head);
        //     head = head->next;
        // }
        // ListNode* ans = node_stack.top();
        // ListNode* res = node_stack.top();
        // node_stack.pop();
        // while(!node_stack.empty())
        // {
        //     res->next = node_stack.top();
        //     node_stack.pop();
        //     res = res->next;
        // }
        // res->next = NULL;
        // return ans;
    }
};
```