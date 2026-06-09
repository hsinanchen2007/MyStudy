```
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;
        ListNode* res=new ListNode(0);
        ListNode* tail=res;
        int len;
        
        while(cur){
            ListNode* temp=cur;
            int value=cur->val;
            for(len=0;temp!=NULL&&temp->val==value;temp=temp->next) //temp指针遍历含相同元素的子序列
                len++;
            
                if(len==1){
                    tail->next=cur;
                    tail=tail->next;
                }
            
                cur=temp; //cur指向新的节点
        }
        tail->next=NULL; //链表结束标记， 一定要加这一句， 否则结果链表会接上cur指针后所有节点
        return res->next;
    
        
    }
```
