```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = new ListNode(0); //新建头节点处理第一个输入节点
        ListNode* p = head;
        while(l1 && l2){ //l1和l2都存在，比较后连接上较小的节点
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1) p->next = l1; //若l1未遍历完直接连接在后端
        if(l2) p->next = l2; //若l2未遍历完直接连接在后端
        return head->next;
    }
};
```
