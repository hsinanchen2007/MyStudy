 代码不是最精简的，但是非常容易理解。 增加两个dummy 指针，两个尾指针，再加一个当间指针。
通过 num 判断 奇偶。
个人觉得代码不一定要追求最精简，在同等复杂度下，容易理解更加优先。尤其是在真实项目中，让其他人能看懂你的代码更加重要，而不是写的短或追求极致，为了减少几个变量而牺牲了可读性。
```c++
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy_odd = new ListNode(0);
        ListNode* dummy_even = new ListNode(0);
        ListNode* odd_tail = dummy_odd;
        ListNode* even_tail = dummy_even;
        ListNode* cur = head;
        int num = 1;
        while(cur != nullptr) {
            if(num % 2 == 1) {
                odd_tail->next = cur;
                odd_tail = odd_tail->next;
            } else {
                even_tail->next = cur;
                even_tail = even_tail->next;
            }
            cur = cur->next;
            num++;
        }
        odd_tail->next = dummy_even->next;
        even_tail->next = nullptr; //注意偶链表的最后是空指针
        return dummy_odd->next;
    }
};
```