### 解题思路
利用快慢指针，当有环的时候，想象一个运动场，跑得快的人一定会追上跑得慢的人。
注意边界条件 `fast->next` 必须有。

时间复杂度：无环：O(n/2),有环最好时间复杂度：O(n)，有环最坏时间复杂度：O(n+k)，k是环的长度
空间复杂度：O(1)

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

        if(!head || !(head->next)){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){ // 加上 fast->next 的原因是当遍历到最后一个的时候
            slow = slow->next;
            fast = fast->next->next;
            if(slow->val == fast->val){
                return true;
            }
        }
        return false;
    }
};
```