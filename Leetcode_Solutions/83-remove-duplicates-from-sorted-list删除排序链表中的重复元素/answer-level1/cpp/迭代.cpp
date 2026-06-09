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
    ListNode* deleteDuplicates(ListNode* head) {
        //迭代
        ListNode *cur = head;
        while(cur && (cur->next))  //注意：当当前节点不为空且当前节点的下个节点也不为空
        {
            if(cur->val == cur->next->val)
            {
                //当前节点值与下一个节点值相等
                ListNode *node = cur->next;
                cur->next = cur->next->next;
                delete node;
            }
            else
            {
                //当前节点值与下一个节点值不相等
                cur = cur->next;  //指针后移
            }
        }
        return head;
    }
};
```