链表的基本删除操作。
因为测试用例的所有重复的值都在一起。
例如1-2-3-3
而不是1-2-1-2-3

输入
[1,2,1,2]
输出
[1,2,1,2]
预期结果
[1,2,1,2]

输入
[1,1,2]
输出
[1,2]
预期结果
[1,2]

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    if(NULL==head->next){
     return head;  
    }
    struct ListNode *temp=head->next;
    struct ListNode *node=head;
    while(temp){
       if(head->val==temp->val){
           head->next=temp->next;
           temp=head->next;
       }
       else{
          head=head->next;
          temp=temp->next;
       }
       
    }
    head=node;
    return head;
}
