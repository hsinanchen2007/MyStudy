## 思路分析
本题为 [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/])和 [876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/) 的结合情况：
1. 先用快慢指针思想找到链表中点；
2. 翻转后半部分链表；
3. 比较值；

## 代码实现
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
        if(head==nullptr) return true;
        // 找到中间节点
        ListNode * cut = middleNode(head);
        //  翻转链表
        cut = reverseList(cut);
        while(cut!=nullptr){
            if(head->val!=cut->val) return false;
            head = head->next;
            cut = cut->next;
        }
        return true;
    }
private:
    ListNode* middleNode(ListNode* head) {
        ListNode * start = new ListNode(0);
        start->next = head;
        ListNode *fast = start, *slow = start;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast==nullptr? slow: slow->next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *p =head;
        while(p!=nullptr){
            ListNode *after = p->next;
            p->next = pre;
            pre = p;
            p = after;
        }
        return pre;
    }
};
```