### 解题思路
使用next的value不断覆盖当前的value， 然后把最后一个value删除。

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
    void deleteNode(ListNode* node) {
        ListNode *p = node->next;
        while(p->next != nullptr){
            node->val = p->val;
            node = p;
            p = p->next;
        }
        node->val = p->val;
        node->next = nullptr;
        delete(p);
        p = nullptr;
    }
};
```