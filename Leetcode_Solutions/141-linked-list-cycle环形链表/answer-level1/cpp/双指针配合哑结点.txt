**思路**
就像运动员赛跑，如果有环形跑道，那么跑的快的运动员一定会追上跑得慢的运动员，如果没有环形跑道，快的运动员跑道终点就会停下了
```
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);//设立哑结点处理只有一个元素的特殊情况
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        while (1)
        {
            if (fast->next->next == nullptr)
                break;
            else
                fast = fast->next->next;//快的每次走两节
            if (slow->next == nullptr)
                break;
            else
                slow = slow->next;//慢的每次走一节
            if (slow == fast)
                return true;
        }
        return false;
    }
};
```
