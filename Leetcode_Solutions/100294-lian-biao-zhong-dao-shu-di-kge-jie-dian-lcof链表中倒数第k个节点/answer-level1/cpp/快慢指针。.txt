### 解题思路
快慢指针。
保持快慢指针之间的距离始终满足k。
快指针走到末尾，那么慢指针的位置刚好就是答案。

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;//快指针
        ListNode* q = head;//慢指针
        int i = 0;//慢指针索引变量
        int j = 0;//快指针索引变量
        while (p)
        {
            while (i<=j-k)
            {
                q = q->next;
                i++;
            }
            j++;
            p = p->next;
        }
        return q;//返回慢指针
    }
};
```