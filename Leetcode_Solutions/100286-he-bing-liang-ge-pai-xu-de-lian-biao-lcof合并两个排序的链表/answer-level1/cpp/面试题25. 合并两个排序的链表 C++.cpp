### 解题思路
此处撰写解题思路

### 代码

```cpp

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

         //判空
        if (!l1)
        {
            return l2;
        }

        if (!l2)
        {
            return l1;
        }

        //先确定头节点
        ListNode* head = nullptr;
        if(l1->val <= l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }

        //再确定其他节点
        ListNode* cur = head;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if(l1)
        {
            cur->next = l1;
        }

        if(l2)
        {
            cur->next = l2;
        }

        return head;
    }
};
```