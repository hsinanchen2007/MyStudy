### 解题思路
找到中间节点，反转后半段，再与前半段逐一比较

注意：使用while(fast->next && fast->next->next)  在元素个数为偶数时，中间节点为两个中间的第一个 
可以对奇数、偶数情况进行统一处理

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

    //反转链表
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr) //空链表和仅一个元素的链表都算回文链表
        {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next) //对偶数个元素，获取的是中间两个节点的第一个
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* head_1 = head;
        ListNode* head_2 = reverse_list(slow->next); //统一处理 从中间节点的下一个节点到尾结点反转

        while(head_2)
        {
            if(head_1->val != head_2->val)
                return false;

            head_1 = head_1->next;
            head_2 = head_2->next;
        }

        return true;
    }
};
```