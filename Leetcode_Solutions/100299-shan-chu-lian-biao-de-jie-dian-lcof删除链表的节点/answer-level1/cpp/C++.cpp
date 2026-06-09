### 解题思路

1、不设置dummy节点 需要对头结点单独处理

2、设置dummy节点 所有节点删除统一处理 注意：返回dummy->next

删除节点 需要先找到该结点的prev结点

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
    ListNode* deleteNode(ListNode* head, int val) {

        if(head == nullptr)
        {
            return head;
        }
        
        ListNode* cur = head;

        if(cur->val == val)
        {
            head = cur->next;
        }
        else
        {
            //找待删除节点的prev节点
            while(cur->next)
            {
                if(cur->next->val == val)
                {
                    cur->next = cur->next->next;
                    break;
                }
                else
                {
                    cur = cur->next;
                }
            }
        }

        return head;
    }

    

    ListNode* deleteNode(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* cur = dummy;

        //找待删除节点的prev节点
        while(cur->next)
        {
            if(cur->next->val == val)
            {
                cur->next = cur->next->next;
                break;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
```