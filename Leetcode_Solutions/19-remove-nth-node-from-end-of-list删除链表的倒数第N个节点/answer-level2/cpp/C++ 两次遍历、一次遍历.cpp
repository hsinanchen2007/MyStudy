关键：是找到倒数第N + 1个节点， 即倒数第N个节点的prev节点
然后就是一般的删除节点代码了：
ListNode* tmp = prev->next;
prev->next = prev->next->next;
delete tmp;


class Solution {
public:

    // 两次遍历 先获取链表长度，再定位prev节点
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     // if (head == nullptr) //测试用例中没有出现head为空的情况
    //     //     return head;

    //     ListNode* dummy = new ListNode(0);
    //     dummy->next = head;

    //     ListNode* cur = head;

    //     //第一次遍历 统计链表节点数
    //     int count = 0;
    //     while (cur)
    //     {
    //         ++count;
    //         cur = cur->next;
    //     }

    //     //第二个遍历，走到倒数第n + 1个节点处,倒数第n个节点的前一个节点(索引为count - n - 1，索引从0开始)
    //     //如果 n == count， 即删除头节点
    //     ListNode* prev = dummy;
    //     int prev_index = -1;
    //     while (prev)
    //     {
    //         if (prev_index == count - n - 1)
    //         {
    //             break;
    //         }

    //         prev = prev->next;
    //         ++prev_index;
    //     }

    //     ListNode* tmp = prev->next;
    //     prev->next = prev->next->next;
    //     delete tmp;

    //     return dummy->next;
    // }


    //一次遍历  双指针，一个指针先走n+1步，第n+2步两个指针再一起走, 最后慢的指针就为prev节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy; 
        ListNode* fast = dummy;

        //循环结束后 slow为倒数第n+1个节点  为倒数第n个节点的prev节点
        //fast需要先走n+1步，第n+2步时slow才与fast一起走
        //根据题意n是保证有效的(1 <= n <= length)，故不存在走完n+1步之前，fast就为空的情况，最多n==length时，fast会为空
        for (int i = 0; i < n + 1; ++i)
        {
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        return dummy->next;
    }
};