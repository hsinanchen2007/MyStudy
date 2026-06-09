
此题特别要注意：测试用例中有k大于链表长度的，需要做k % length取余操作

class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k <= 0)
            return head;

        //1、找到倒数第k+1个节点，它的next为倒数第k个节点
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail = nullptr;

        
        // fast先走k+1步   
        int i = 0;
        for (; i < k + 1; ++i)
        {
            if (fast == nullptr)
                break;

            if (fast->next == nullptr)  //获取尾结点
                tail = fast;

            fast = fast->next;
        }

        if (fast == nullptr) //k + 1 >= 链表长度
        {
            int length = i; //链表长度

            k = k % length;

            if (k == 0)
            {
                return head;
            }

            // 0 < k < length
            if (k + 1 == length) // k == length - 1  slow即为head
            {
                slow = head;
            }
            else  //k < length - 1
            {
                fast = head;

                // fast先走k + 1步   
                for (int i = 0; i < k + 1; ++i)
                {
                    fast = fast->next;
                }

                //从第k + 1步  slow与fast一起走
                while (fast)
                {
                    if (fast->next == nullptr)
                    {
                        tail = fast; //找到尾节点
                    }
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }

        else //fast非空  k + 1 < 链表长度
        {
            //从第k+1步  slow与fast一起走
            while (fast)
            {
                if (fast->next == nullptr)
                {
                    tail = fast; //找到尾节点
                }
                fast = fast->next;
                slow = slow->next;
            }
        }

        //slow为倒数第k+1个节点

        ListNode* last_k = slow->next; //倒数第k个节点

        //倒数第k+1个节点设置为新尾节点
        slow->next = nullptr;

        //原尾节点next设置为原首节点(尾首相接)
        tail->next = head;

        //原倒数第k个节点设置为新的首节点
        head = last_k;

        return head;
    }
};