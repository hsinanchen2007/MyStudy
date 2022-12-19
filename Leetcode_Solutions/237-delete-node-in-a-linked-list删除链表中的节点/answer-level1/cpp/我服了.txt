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
       // *node = *(node->next);

       //因为无法获得上一个节点的地址，所以将下一个节点的值复制到当前节点，并删除下一个结点
        node->val=node->next->val;
        node->next=node->next->next;
    }
};