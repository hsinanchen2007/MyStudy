### 解题思路
日常参考 @Krahets 思路。
双指针，一个指上一个节点，一个指向当前节点。C++实现一哈。

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
            return head->next;
        ListNode* preNode = head;
        ListNode* curNode = head->next;
        while( curNode != NULL && curNode->val != val)
        {
            preNode = curNode;
            curNode = curNode->next;
        }
        if(curNode == NULL)
            return head;
        else
             preNode->next = curNode->next;
        return head;
    }
};
```