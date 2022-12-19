
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode * result, *t, *p, *q;

        // 存在空链表情况
        if(l1 == NULL)
            return l2;
        if(l2 == NULL )
            return l1;

        // 将链表合并到首节点较小的节点
        result = l1->val <= l2->val? l1 : l2;
        t = result;

        // 处理首节点
        if(t == l1) {
            p = l1->next;
            q = l2;
        } else {
            p = l1;
            q = l2->next;
        }
        
        while(p != NULL && q != NULL){
            if(p->val <= q->val){
                t->next = p;
                t = p;
                p = p->next;        
            }else{
                t->next = q;
                t = q;
                q = q->next;
            }
        }

       // 处理未链接的节点
        if(p == NULL) {
            t->next = q;
        } else if(q == NULL) {
            t->next = p; 
        }

        return result;
    }
};