思路：快慢指针赛跑，慢的指针每次走一步，快的指针每次走两步，当两个指针指向的内存地址一样时，说明有环，但是相遇的地点并不一定是环的起点。从相遇位置和链表头一起走，每次走相同的步数，再次相遇时即为环的起点（相遇的位置也可能是环的起点，当直线距离等于环线距离时，相遇位置即为环的起点）。
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {     
        //声明并初始化快慢指针，以及相遇的结点
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * meet = NULL; 
        while(fast)
        {
            slow = slow -> next;
            fast = fast -> next;
            //每循环一次，slow走一步，fast走两步，必定是fast最先到达链表尾
            if (!fast)
            {
                return NULL;
            }
            else
                fast = fast -> next;
            if (fast == slow)
            {
                //fast与slow相遇，记录相遇位置
                meet = fast;
                break;
            }
        }
        //如果链表为空链表或者链表无环
        if (meet == NULL)
        {
            return NULL;         //如果没有相遇，则证明无环
        }
        while(head && meet)
        {
            //当head与meet相遇，说明遇到环的起始位置
            if (head == meet)
            {
                return head;
            }
            //从head与meet出发，两指针速度一样，相遇时即为环的起点。meet可能走好几圈才能遇上head。  
            head = head -> next;
            meet = meet -> next;
        }
        return NULL;
    }
};```
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {     
        //声明并初始化快慢指针，以及相遇的结点
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * meet = NULL; 
        while(fast)
        {
            slow = slow -> next;
            fast = fast -> next;
            //每循环一次，slow走一步，fast走两步，必定是fast最先到达链表尾
            if (!fast)
            {
                return NULL;
            }
            else
                fast = fast -> next;
            if (fast == slow)
            {
                //fast与slow相遇，记录相遇位置
                meet = fast;
                break;
            }
        }
        //如果链表为空链表或者链表无环
        if (meet == NULL)
        {
            return NULL;         //如果没有相遇，则证明无环
        }
        while(head && meet)
        {
            //当head与meet相遇，说明遇到环的起始位置
            if (head == meet)
            {
                return head;
            }
            //从head与meet出发，两指针速度一样，相遇时即为环的起点。meet可能走好几圈才能遇上head。  
            head = head -> next;
            meet = meet -> next;
        }
        return NULL;
    }
};
```
