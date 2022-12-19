![image.png](https://pic.leetcode-cn.com/2202a0d2c9cd4bf61bd22c8199659cb65a258ce9a5c3ac590e76a5ee1b61c5e5-image.png)

### 解题思路
双指针，遍历一趟，见下图。
![image.png](https://pic.leetcode-cn.com/6a18fd8627f7c723a60cff766b80bcb7e50e66667758c07837000202b3fd5305-image.png)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        while(n-- > 0){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        ListNode* slow = head;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
```