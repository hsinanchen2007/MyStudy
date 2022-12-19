### 解题思路
查找到a->next==val,a->next=a->next->next
特殊情况：
1、只有一个节点，删除完head=nullptr
2、删除最后一个节点时，a->next=nullptr


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
        if(head->next==nullptr) return nullptr;
        ListNode* a=head;//
        if(a->val==val)
        {
            head=head->next;
            return head;
        }
        while(a->next!=nullptr)
        {
            if(a->next->val==val)
            {
                if(a->next->next==nullptr) {a->next=nullptr;return head;}
                else a->next=a->next->next;
            }
            a=a->next;
        }
        return head;

    }
};
```