1.快慢指针找到链表的中间节点
2.翻转中间节点之后的后半部分链表
3.开始比较前面和后面
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = head;
        ListNode* cur = head;
        //找到中间节点
        while(cur != nullptr)
        {
            cur = cur->next;
            if(cur == nullptr)
                break;
            mid = mid->next;
            cur = cur->next;
        }
        //翻转后半部分链表
        ListNode* rhead = nullptr;
        ListNode* ret = mid;
        while(ret != nullptr)
        {
            ListNode* next = ret->next;
            ret->next = rhead;
            rhead = ret;
            ret = next;
        }
        //开始比较
        ListNode* front = head;
        ListNode* rear = rhead;
        while(front != nullptr && rear != nullptr)
        {
            if(front->val == rear->val)
            {
                front = front->next;
                rear = rear->next;
            }
            else 
                return false;
        }
        return true;
    }
};
```
