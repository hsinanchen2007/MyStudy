class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *node_x = headA;
        ListNode *node_y = headB;
        while(node_x != node_y){
            node_x = node_x ? node_x->next : headB;
            node_y = node_y ? node_y->next : headA;
        }
        return node_x == node_y ? node_x : NULL;
    }
};