```cpp
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)
        return head;
        ListNode* ji_node=head;
        ListNode* ou_node=head->next;
        ListNode* ind_ou=head->next;
        int i=0;
        while(ou_node->next&&ou_node->next->next)//让奇数节点的下一数组成为奇数节点,偶数节点下一节点为偶数节点
        {
            ji_node->next=ou_node->next;
            ji_node=ji_node->next;
            ou_node->next=ji_node->next;
            ou_node=ou_node->next;
        }
        if(ou_node->next)//此时ou_node后还有一位奇数节点
        {
        ji_node->next=ou_node->next;
        ji_node=ji_node->next;
        ou_node->next=NULL;
        }
        ji_node->next=ind_ou;//让奇偶节点相连接
        return head;
    }

```