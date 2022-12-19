### 解题思路
此处撰写解题思路
使用两个指针，一个指针每次走两步，另一个指针每次走一步；
当第一个指针走到链表结尾时，第二个指针刚好指向中间节点。
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
    ListNode* middleNode(ListNode* head) {
       if(head==nullptr)
       return nullptr;
       ListNode* pNode1=head;
       ListNode* pNode2=head;
       while(pNode1->next!=nullptr)
       {
           pNode1=pNode1->next;
           if(pNode1->next!=nullptr)
           pNode1=pNode1->next;
           pNode2=pNode2->next;
       }
       return pNode2;
    }
};
```