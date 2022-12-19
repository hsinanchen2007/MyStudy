### 解题思路
递归法：让当前节点指向剩下的所有节点

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
        //head==null是否为空链
        //head->next==null是否递归到最后一个字节，并返回他
        if(head==NULL||head->next==NULL)return head;
        head->next=deleteDuplicates(head->next);
        return (head->val==head->next->val)?head->next:head;
    }
};
```