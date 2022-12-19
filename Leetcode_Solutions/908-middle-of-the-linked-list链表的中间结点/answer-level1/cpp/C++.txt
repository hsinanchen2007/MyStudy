### 解题思路
此处撰写解题思路
很简单的思路，见代码
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
        ListNode* mid = head;
        int length = 0;
        int count = 1;
        while (head)
        {
            length++;
            if (length / 2 >= count)
            {
                count++;
                mid = mid->next;
            }
            head = head->next;
        }
        return mid;
    }
};
```