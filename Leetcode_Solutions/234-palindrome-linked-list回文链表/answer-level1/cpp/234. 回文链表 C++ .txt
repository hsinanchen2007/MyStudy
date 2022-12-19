快慢指针 和 反转链表  时间复杂度O(n) 空间复杂度O(1)


```cpp
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    //版本一
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) //空链表和仅一个元素的链表都算回文链表
        {
            return true;
        }

        //1、找中间节点
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //2、反转链表
        ListNode* head_1 = head;
        ListNode* head_2 = nullptr;

        if(fast == nullptr) //元素总数为偶数
        {
            //将中间节点到尾节点反转 
            head_2 = reverseList(slow);   
        }
        else if(fast->next == nullptr) //元素总数为奇数
        {
            //将中间节点的next节点到尾节点反转
            head_2 = reverseList(slow->next); 
        }

        //3、比较
        // while (head_1 != slow) //从head_1到中间节点的prev节点
        while(head_2) //或从head_2到结束
        {
            if (head_1->val != head_2->val)
            {
                return false;
            }
            head_1 = head_1->next;
            head_2 = head_2->next;
        }

        return true;
    }

    //版本二  奇、偶个数可以统一处理
    bool isPalindrome_v2(ListNode* head) {

        if (head == nullptr || head->next == nullptr) //空链表和仅一个元素的链表都算回文链表
            return true;

        //1、找中间节点
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next) //对偶数个元素，获取的是中间两个节点的第一个
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //2、反转
        ListNode* head_1 = head;
        ListNode* head_2 = reverseList(slow->next); //从中间节点的下一个节点到尾结点反转

        //3、比较
        while (head_2) //比至head_2结束
        {
            if (head_1->val != head_2->val)
            {
                return false;
            }
            head_1 = head_1->next;
            head_2 = head_2->next;
        }

        return true;
    }
};