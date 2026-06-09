### 解题思路
栈的先进后出，后进先出的思想

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
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        stack<ListNode*> node;
        while(!head)//链表为空
        {
            return {};
        }
        while(head)//遍历链表把值压入栈
        {
            node.push(head);
            head=head->next;
        }
        while(!node.empty())
        {
            head=node.top();
            result.push_back(head->val);
            node.pop();
        }
        return  result;

    }
};
```