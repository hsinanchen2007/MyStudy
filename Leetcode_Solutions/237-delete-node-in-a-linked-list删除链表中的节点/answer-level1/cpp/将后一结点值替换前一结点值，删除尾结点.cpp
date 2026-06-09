class Solution {
public:                                //将后一结点值替换前一结点值，删除尾结点
    void deleteNode(ListNode* node) {
        ListNode *L=NULL;              //记录尾前节点
        while(node->next)
        {
            node->val=node->next->val;
            L=node;
            node=node->next;           //找到尾前节点L，尾结点node
        }
        ListNode *swap = node;         //交换结点信息，使node指向尾前结点，L指向尾后结点
        node = L;
        L = swap;
        node->next=L->next;
    }
};