### 解题思路
![linklist_circle.jpg](https://pic.leetcode-cn.com/19c312bd39e47d6f55937567652ca9b65d4e358e6d15fc8b6e6339d66a2bef09-linklist_circle.jpg)
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

        ListNode *node1, *node2;

        node2 = head;
        node1 = FloydPhase1(head);
        if(!node1)
        {
            return NULL;
        }

        while(node1 != node2)
        {
            node1 = node1->next;
            node2 = node2->next;
        }

        return node2;
    }
private:
    ListNode *FloydPhase1(ListNode *head)
    {
        ListNode *slow, *fast;
        slow = fast = head;
        while(slow && fast)
        {
            slow = slow->next;
            if(!fast->next) 
            {
                return NULL;
            }  
            fast = fast->next->next;

            if(fast == slow)
                return fast;
        }

        return NULL;
    }
};
```