### 解题思路
注意 while 中的判断也需要判断 cur 指针不为空

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
        // 虚拟头节点
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *cur = temp;
        while(cur && cur->next) {
            // 需要也判断 cur 存在的原因：最后一个了节点为被删除节点的时候
            if(cur->next->val==val) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return temp->next;
    }
};
```