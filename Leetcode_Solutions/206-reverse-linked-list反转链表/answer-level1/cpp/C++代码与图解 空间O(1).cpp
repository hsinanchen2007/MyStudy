### 解题思路
![image.png](https://pic.leetcode-cn.com/4507235cd62c01253f6f1f2f22279c834a49783f5091ebcede02c68e1041de7e-image.png)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* after = current->next;
            current->next = previous;
            previous = current;
            current = after;
        }

        return previous;
    }
};

```