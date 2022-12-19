### 解题思路
关注微信公众号'码农黑板报' 获取更多题解
![image.png](https://pic.leetcode-cn.com/c27059ecf1446d2d2a330c63d14871a7dba4b2f62fb63619bafb6d27668dcc60-image.png)


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
        if (head == NULL) {
            return NULL;
        }
        ListNode* p = new ListNode(0);
        ListNode* q = new ListNode(0);
        p->next = head;
        q = p;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return q->next;
    }
};
```