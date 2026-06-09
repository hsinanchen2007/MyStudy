## 思路
为了简化删除头节点操作，新建一个虚拟头节点 tmp 并设置 tmp->next = head。

### 代码

```cpp
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *tmp = new ListNode(0), *pre = tmp, *cur = head;
        tmp->next = head;
        while (cur) {
            if (cur->val == val) {                
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return tmp->next;
    }
};
```