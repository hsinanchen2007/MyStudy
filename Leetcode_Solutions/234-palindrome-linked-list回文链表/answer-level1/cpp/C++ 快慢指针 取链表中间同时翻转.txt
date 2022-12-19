
使用2个指针，一个first，一个second，second的速度是first的2倍，使用first移动到链表中间，在移动指针时同时对前半部分链表进行反转，根据second是否为nullptr判断奇偶。

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return true;
        
        ListNode* first = head;
        ListNode* second = head;
        
        ListNode* rev = head;
        ListNode* pre = nullptr;
        
        while(second != nullptr && second->next != nullptr)
        {
            rev = first;
            first = first->next;
            second = second->next->next;
            rev->next = pre;
            pre = rev;
        }
        ListNode* p1 = second == nullptr? first : first->next;
        
        ListNode* p2 = rev;
        
        while(p1 != nullptr)
        {
            if(p1->val != p2->val) return false; 
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};