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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* root = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = root;
            root = head;
            head = next;
        }
        return root;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }  
        if (fast) // 长度为奇 5 / 2 = 2 
            slow = slow->next;
        slow = reverse(slow);
        while (head && slow) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;

    }
};
```