### 解题思路
先遍历求长度，然后再找中间节点返回即可。

### 代码

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *q = head;
        int len = 0;
        while(q!=NULL)
        {
            len++;
            q = q->next;
        }
        len = len/2;
        q = head;
        while(len)
        {
            q = q->next;
            len--;
        }
        return q;
    }
};
```