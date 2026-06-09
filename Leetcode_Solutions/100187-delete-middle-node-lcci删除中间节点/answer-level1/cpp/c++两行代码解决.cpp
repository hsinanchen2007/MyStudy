// ### 解题思路
// 将node->next的值赋给node,然后将node指向下下个节点。

// 如果代码有问题，欢迎在评论区指出。
// 如果感到有帮助，欢迎点赞😊。
// ### 代码

// ```cpp
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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
// ```