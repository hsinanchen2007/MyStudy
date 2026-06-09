### 解题思路
* 先检查特殊情况: 链表长度是否为0 / 1. 两种情况都被看作回文链表，return true。
* 通过快慢指针获得中点，以及中点分隔开的左右两部分链表的起始位置（起始位置在长度为奇数和长度为偶数时不同）
* 反转左手链表并遍历左右手链表对比各个值 （若遇到值不同 则不是回文链表 return false）
* 遍历结束时若遍历使用的两指针有一个不为nullptr, 则说明左右手链表长度不同, 并非回文链表, return false.
* 将左手链表翻转复原。
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
    bool isPalindrome(ListNode* head) {
        // 0. ALWAYS think of special case when pass in a pointer
        // In this case, length 0 and length 1 are edge cases.
        // They are both considered palindrome.
        if(!head) return true;
        if(!(head->next)) return true;

        // 1. Get Mid Point and Even/Odd Length
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // If fast is not null, i.e. (fast->next) is null, odd length.
        bool is_even = fast ? false : true;

        // 2. Reverse Linked List
        ListNode *first_begin, *second_begin;
        ListNode* midnode = slow; // defined to be mid or to the right of the mid (in even case)
        second_begin = is_even ? midnode : midnode->next;
        first_begin = reverse_singly_linked(head, midnode);

        while(first_begin && second_begin){
            if(first_begin->val != second_begin->val) return false;
            first_begin = first_begin->next;
            second_begin = second_begin->next;
        }
        if(first_begin || second_begin) return false;
        reverse_singly_linked(first_begin, nullptr, midnode);
        return true;
    }

private:
    // REQUIRE: `end` points to 1 node after the end node of linked list need to be reversed.
    // could be nullptr.
    // EFFECT: It will return the head node of reversed linked list
    ListNode* reverse_singly_linked(ListNode* begin, ListNode* end, ListNode* connect_end_to = nullptr){
        ListNode *prev = connect_end_to;
        ListNode *curr = begin;
        while(curr != end){
            ListNode* next_tmp = curr->next;
            curr->next = prev; // Rewrite curr->next
            prev = curr;
            curr = next_tmp;
        }
        return prev;
    }
};
```