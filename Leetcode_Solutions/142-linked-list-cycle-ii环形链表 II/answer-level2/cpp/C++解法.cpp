### 解题思路
首先用快慢指针，慢指针走一步，快指针走两步，如果有环，快指针走了一圈又碰到慢指针。
判断出有环之后，我们就要算出环的大小。算出环的大小，然后让一个指针先走一环的路，然后另一个指针从头开始出发。当两者相等的时候，就是环的入口节点了

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
    ListNode * MeetingNode(ListNode * head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode * slow = head->next;
        if(slow == nullptr)
        {
            return nullptr;
        }
        ListNode * fast = slow->next;
        while(fast != nullptr && slow != nullptr)
        {
            if(fast == slow)
            {
                return fast;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr)
                fast = fast->next;
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode * meetingNode = MeetingNode(head);
        if(meetingNode == nullptr)
            return nullptr;
        int nodesInLoop = 1;
        ListNode * node = meetingNode;
        while(node->next != meetingNode)
        {
            node = node->next;
            ++nodesInLoop;
        }
        node = head;
        for(int i = 0; i < nodesInLoop; ++i)
        {
            node = node->next;
        }
        ListNode* node2 = head;
        while(node != node2)
        {
            node = node->next;
            node2 = node2->next;
        }
        return node;
    }
};
```