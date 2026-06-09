/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head){
    if( head == NULL || head->next == NULL || head->next->next == NULL)return;
    struct ListNode* cur    = head;
    struct ListNode* before = head;
    struct ListNode* behind = NULL;
    int count = 0;//链表长度
    
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    
    count = (count%2)?(count/2):(count/2-1);//单数长度的链表只需要count/2次转换，双数count/2-1

    for(int i = 0; i<count; ++i)
    {
        while(cur->next != NULL && cur->next->next != NULL) cur = cur->next;//最后一个元素的前一个元素
        behind = cur->next;
        cur->next = NULL;//最后一个提出来了，把原来的次节点的next指向NULL
        
        //插入操作，before为插入的前节点
        behind->next  = before->next; //先连接
        before->next  = behind;       
        before        = behind->next;  
        
        cur = before;//更新cur，从新遍历找最后的节点
    }
}