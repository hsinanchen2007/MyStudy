### 解题思路
此处撰写解题思路
参考了实现。 画示意图， 列方程解答。 得出 获得相遇点之后。 快的从相遇点出发，每次走一步， 等同于慢的从链表表头出发，每次走一步， 最终相遇的点即为首次相遇的点。

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
    ListNode *detectCycle(ListNode *head) {
         ListNode *p1=head, *p2=head;
        while(p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) {
                p2 = p2->next;
            };
            if ((p1==p2) && (p1!=NULL)) {
                ListNode *p3 = head, *p4 = p2;
                while (p3 != p4) {
                    p3 = p3->next;
                    p4 = p4->next;
                }
                return p3;
            }
                
        }
        return NULL;
        
    }
};
```