/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int ret = 0; //定义一个进位
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next = NULL;  
    struct ListNode* head = l3;   //让 head 作为头节点
    while(l1 != NULL || l2 != NULL)
    {
        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode)); //开辟一个节点，并把地址给 cur
        l3->next = cur;     //让l3 指向 cur
        cur->next = NULL;   //让cur指向NULL
        if(l1 != NULL && l2 != NULL)     //三种情况，l1为空 l2不空,l2为空 l1不空,l1 l2 均不为空
         cur->val = l1->val + l2->val + ret;
        else if(l1 != NULL)
            cur->val = l1->val + ret;
        else if(l2 != NULL)
            cur->val = l2->val + ret;
        if(cur->val > 9)
        {
            ret = 1;
            cur->val %= 10;        //大于10则取余并把进位置为1
        }
        else
            ret = 0;
        l3 = cur;
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;        
    }
    if(ret > 0)     //判断最后一个节点是否超出范围，用ret作为判断标准
    {
         struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
         l3->next = cur;
         cur->next = NULL;     //一定记得让cur 指向NULL
         cur->val = 1;
         l3->val %= 10;
    }
    return head->next;      //返回头节点的 next

}

