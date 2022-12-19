### 解题思路
构建两个链表，left和right；
left初始化为空，right初始化为head；
然后逐渐迭代下去就可以了。

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
        ListNode* left = NULL;
        ListNode* right = head;
        while(right != NULL){
            ListNode* temp = right->next;
            right->next = left;
            left = right;
            right = temp;
        }
        return left;
    }
};
```