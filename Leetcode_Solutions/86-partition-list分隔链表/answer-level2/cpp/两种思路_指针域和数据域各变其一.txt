思路一：不改变指针域，只调换数据域。即不变位置，只变存储位置的值。这个思路中我利用了栈顶弹出压入的快捷性。这个思路代码很清晰，时间复杂度较好，但空间复杂度较差。
```
    ListNode* partition(ListNode* head, int x) {
        ListNode *p=head;
        vector<int>little_x;
        vector<int>big_x;
        
        while(p){
            if((p->val)<x)
                little_x.push_back(p->val);
            else
                big_x.push_back(p->val); 
            p=p->next;
        }
        
        vector<int>temp_val;
        while(!big_x.empty()){
            temp_val.push_back(big_x.back());
            big_x.pop_back();
        }
        while(!little_x.empty()){
            temp_val.push_back(little_x.back());
            little_x.pop_back();
        }        
        
        p=head;
        while(!temp_val.empty()){
            p->val=temp_val.back();
            temp_val.pop_back();
            p=p->next;
        }
        return head;
    }
```
性能：8ms,8.9MB


思路二：不改变换数据域，只改变指针域。即不挪数据，只改变指针指向。这个思路中利用了两对头尾双指针，分别记录大小两个链的头尾节点，head指针作为遍历指针用。s时间复杂度较好，但空间复杂度略差。（由于在head每前进一个节点都要判断大小链是否为空以便尾指针正确移动，造成了空间和时间的浪费，这时用临时节点或许更优）
```
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode *less_x=NULL;
        ListNode *bigger_x=NULL;
        ListNode *less_tail=NULL;
        ListNode *bigger_tail=NULL;
        while(head){
            if(head->val<x){
                if(less_x==NULL)
                    less_x=head;
                else
                    less_tail->next=head;  
                less_tail=head;       
            }
            else{
                if(bigger_x==NULL)
                    bigger_x=head;
                else
                    bigger_tail->next=head;  
                bigger_tail=head;  
            }
            head=head->next;
        }
        if(less_tail==NULL)
            return bigger_x;
        less_tail->next=bigger_x;
        if(bigger_tail!=NULL)
            bigger_tail->next=NULL;
        return less_x;  
    }
```
运行结果：8ms,8.7MB
