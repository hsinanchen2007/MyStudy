### 解题思路
 即不断地使当前结点指向前一个结点，便实现了反向。切记：在指向前务必先保存当前结点的下一个结点!
 执行时间击败70.58%，内存消耗击败100%。

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
        // 双指针法
        ListNode* pre = NULL;
        ListNode* cur = head;

        while(cur != NULL)
        {
            ListNode*p = cur->next;
            cur->next = pre;
            pre = cur;
            cur = p;
        }

        delete cur; // 空结点，删除

        return pre;
    }
};
```