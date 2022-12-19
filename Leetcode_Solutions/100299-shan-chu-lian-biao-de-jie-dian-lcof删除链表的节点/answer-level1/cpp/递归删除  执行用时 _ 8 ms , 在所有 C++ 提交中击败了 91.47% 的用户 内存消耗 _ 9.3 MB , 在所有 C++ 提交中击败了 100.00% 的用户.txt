### 解题思路
输入空指针时返回空指针，到达链表尾部没删除返回空指针；
删除节点并返回下个节点，没删除返回自己；
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
        if(head==nullptr) return nullptr;
        if(head->val==val) return head->next;
        head->next=deleteNode(head->next,val);
        return head;
    }
};
```