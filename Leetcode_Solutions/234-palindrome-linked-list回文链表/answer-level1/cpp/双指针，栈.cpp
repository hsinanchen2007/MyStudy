### 解题思路
这道题首先想到的是前一道题的反转链表。然后比较反转后的链表和原链表。但是不知道为什么就是错的。。。

看了解题后发现用双指针，把前半部分逆序，和后半部分比较。
还有就是栈。直接把所有节点值压进去。再弹出来比较。

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

    // 执行用时 :40 ms, 在所有 C++ 提交中击败了16.47% 的用户
    // 内存消耗 :13.4 MB, 在所有 C++ 提交中击败了11.94%的用户
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode* fast = head, *slow = head;
        ListNode* p , *pre = nullptr;
        while(fast&&fast->next){  //通过慢指针找到中点。
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
            p->next = pre;
            pre = p;
        }
        if(fast) slow = slow->next; //若为单数。slow右移一位。
        while(p){
            if(slow->val != p->val) 
                return false;
            slow = slow->next;
            p = p->next;
        }
        return true;
    }

    // 执行用时 :36 ms, 在所有 C++ 提交中击败了23.68% 的用户
    // 内存消耗 :14.8 MB, 在所有 C++ 提交中击败了5.04%的用户
    bool isPalindrome(ListNode* head){
        if(!head||!head->next) return true;
        stack<int> sl; //使用栈保存节点值。
        ListNode* p = head;
        while(p){
            sl.push(p->val);
            p = p->next;
        }
        p = head;
        while(p){
            if(p->val != sl.top()) return false;
            sl.pop();
            p = p->next;
        }
        return true;
    }
    

    // bool isPalindrome(ListNode* head){
    //     if(!head||!head->next) return true;
    //     ListNode* copy = head;
    //     ListNode* pre = nullptr, *temp;
    //     ListNode* node = new ListNode(head->val);
    //     node->next = head->next;
    //     while(node){
    //         temp = node->next;
    //         node->next = pre;
    //         pre = node;
    //         node = temp;
    //     }
    //     while(pre){
    //         if(pre->val!=copy->val) return false;
    //         pre = pre->next;
    //         copy = copy->next;
    //     }
    //     return true;
    // }
};
```