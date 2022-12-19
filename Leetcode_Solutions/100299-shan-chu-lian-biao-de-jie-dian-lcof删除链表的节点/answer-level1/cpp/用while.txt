### 解题思路
while循环中判断next存在与否，next所指的值是否等于val，如果是，则返回这个节点的父结点。

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
    if(head == NULL)
        return NULL;
    if(head->val == val)
    {
        head = head->next;
        return head;
    }
    ListNode* original , *fa;
    original = head;
    while(original && original->val!=val)
    {   
        fa = original;
        original = original->next;
    }
    if(original == NULL)
        return head;
    else
    {
        fa->next = original->next;
        return head;
    }  
}
};
```