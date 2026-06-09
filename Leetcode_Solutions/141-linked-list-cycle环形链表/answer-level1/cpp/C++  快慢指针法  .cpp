### 解题思路
注意循环退出和return false条件的判断！
执行用时: 12 ms, 在所有 C++ 提交中击败了82.63%的用户
内存消耗: 7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *p, *q;
        p = head;
        q = head->next;
        while(p != q)
        {
            if (q == NULL || q->next == NULL) {
                return false;
            }
            p = p->next;
            q = q->next->next;
        }
        return true;
    }
};


```