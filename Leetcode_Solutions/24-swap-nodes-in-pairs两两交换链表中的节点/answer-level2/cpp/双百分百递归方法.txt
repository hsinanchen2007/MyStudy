### 解题思路
![image.png](https://pic.leetcode-cn.com/614a4cb3335bb8552850d68acd345c0944bffb7c96dde1d096a423b12654593f-image.png)

1. temp 存储下下个节点
2. new_node 存储下个节点作为交换后的头节点
3. head下个节点指向head,
4. head指向F(temp)


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
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode* temp = head->next->next;
        ListNode* new_node = head->next;
        head->next->next = head;
        head->next = swapPairs(temp);
        return new_node;
    }
};
```