### 解题思路
 // 思路：
 // 1. 删除所有重复元素，还是排好序的，那就直接遍历呗
 // 2. 两个指针，一个指向当前指针，一个指向当前的上一个指针
 // 3. 当前节点与上一个节点重复时，删除当前节点，让上一个节点指向当前节点的下一个节点，下一个节点变为当前节点
 // 4. 然后继续判断与上一个节点的值是否重复，如果不再重复了，则上一个节点和当前节点都往后移一位，直到末尾。

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

 // 思路：
 // 1. 删除所有重复元素，还是排好序的，那就直接遍历呗
 // 2. 两个指针，一个指向当前指针，一个指向当前的上一个指针
 // 3. 当前节点与上一个节点重复时，删除当前节点，让上一个节点指向当前节点的下一个节点，下一个节点变为当前节点
 // 4. 然后继续判断与上一个节点的值是否重复，如果不再重复了，则上一个节点和当前节点都往后移一位，直到末尾。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre= head; // 当前节点的上一个节点, 一开始也让指向头元素
        ListNode *curr=head; // 当前节点

        while (curr != NULL) {
            if(pre->val == curr->val) {
                pre->next = curr->next;
            } else {
                pre = curr;
            }
            curr = curr->next;

        }
        return head;

        
    }
};
```