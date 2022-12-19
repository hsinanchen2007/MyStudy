![image.png](https://pic.leetcode-cn.com/633542597311698a30bda942bbaaa06eb4b1132bd7e765c09f157ffd952bece4-image.png)
执行0ms
### 解题思路
递归进行两两交换。
五行代码实现

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head; //终止条件
        ListNode* node = head->next; 
        head->next = swapPairs(head->next->next);
        node->next = head;
        return node;
    }
};
```