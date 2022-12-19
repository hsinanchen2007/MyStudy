### 解题思路
递归，参考评论第一的那位大佬写的代码

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
    ListNode* deleteDuplicates(ListNode* head) {
        //特例判断
        if(!head || !head->next)//本小白喜欢用！代码少，自己爽hhh
            return head;
        //我调我自己
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val?head->next:head;//三目运算符，简化的if-else语句，判断head和head->next的数据域是否相等

        
    }
};
```