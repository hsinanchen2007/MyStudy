### 解题思路
![Snip20200401_5.png](https://pic.leetcode-cn.com/fb4ac997e3771e433536dd2706406b795831bc5fa7baa0d2513e8f1812749794-Snip20200401_5.png)
此处撰写解题思路

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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;

        // 检测检测链表是否有循环
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                cycle = true;
                break;
            }
        }

        if(!cycle)
        {
            return nullptr;
        }

        // 找出循环开始的位置
        //现在只是判断出有环,快的追上了慢的
        //但是开始的位置还是没有进行判断
        ListNode* p = head;
        while(p != fast)
        {
            p = p->next;
            fast = fast->next;
        }
        return p;
    }
};

```