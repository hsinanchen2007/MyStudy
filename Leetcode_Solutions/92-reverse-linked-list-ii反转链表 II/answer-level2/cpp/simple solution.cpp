感觉只要掌握头插法翻转链表题，很多翻转变形的链表题都迎刃而解。
因为n可能为1，所以使用一个dummy node使得问题可以更简单一些。
解法：
    1： 找到第n-1个节点node。翻转node->next k次，k=m-n+1；
    2： 翻转代码中，将tail初始化为当前head，翻转后将为尾置节点，然后连接未翻转的剩余节点。
时间复杂度: O(n - m + 1)
空间复杂度：O(1)
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
    ListNode* reverse(ListNode* head, int k) {
        ListNode *new_head = nullptr， *tail = head;
        while (head != nullptr && k--) {
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        tail->next = head;
        return new_head;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || m >= n) return head;
        ListNode pre(0), *root = &pre;
        root->next = head;
        int k = n - m + 1;
        while (root && -- m) root = root->next;
        root->next = reverse(root->next, k);
        return pre.next;
    }
};
