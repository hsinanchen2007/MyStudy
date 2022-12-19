### 解题思路
使用快慢指针p1、p2可以得到中间节点。但是要求双中间节点返回第二个，则需要记录一共多少个节点，奇数则返回当前慢指针指向的节点，否则返回当前节点的下一个节点。

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
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p1, *p2;
        p1 = head;
        p2 = head->next;
        int n = 2;

        while (p2 != NULL && p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
            n++;
            if (p2->next != NULL)
            {
                p2 = p2->next;
                n++;
            }
        }
        if (n % 2 == 0)
            return p1->next;
        return p1;
    }
};
```