### 解题思路
见注释

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
    ListNode* deleteDuplicates(ListNode* head) { // 双指针法
        if(!head) // 输入为空，直接返回；
            return head;

        ListNode* i = head;       // 慢指针
        ListNode* j = head->next; // 快指针

        while(j){ // 遍历链表
            if(j->val != i->val){ // 如果快指针j的值与慢指针i的值不重复，将慢指针i连接上快指针j，然后慢指针i跟上。否则快指针j继续向下遍历，直到找到不重复的元素。
                i->next = j;
                i = j;
            }
            j = j->next;
        }
        i->next = j; // 快指针j指向NULL，慢指针i之后没有新元素或者元素为重复值。
        return head;
    }
};
```