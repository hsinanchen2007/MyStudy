class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;
        ListNode *prev = NULL;
        if(head != NULL && head->next != NULL)
            head = head->next;
        while(p != NULL && p->next != NULL)
        { 
            ListNode *three = p->next->next;  //保存第三个
            p->next->next = p;  //使第二个结点连接到第一个
            if(prev != NULL)
                prev->next = p->next; //使上次交换结点连接到本次交换
            p->next = three;    //使第一个结点连接到第三个
            prev = p;
            p = three;  //更新
        }
        return head;
    }
};