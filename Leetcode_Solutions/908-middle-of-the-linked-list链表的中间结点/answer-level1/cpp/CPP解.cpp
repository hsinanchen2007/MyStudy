### 解题思路
双指针，中间节点就是第一个指针走两步，中间节点的指针走一步即可

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
    ListNode* middleNode(ListNode* head) {
        auto p = head;
        auto mid = head;
        bool istwo = false;
        while(p != NULL)
        {
            if(istwo)
            {
                mid = mid->next;
                istwo = false;
            }
            else
            {
                istwo = true;
            }
            p = p->next;
        }
        return mid;
    }
};
```