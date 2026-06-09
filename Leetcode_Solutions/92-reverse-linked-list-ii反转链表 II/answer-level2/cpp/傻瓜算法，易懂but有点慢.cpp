class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL) return head;
        if(m==n) return head;
        ListNode *t1=head;
        ListNode *t2=head;
        ListNode *p=head;
        int num=1;
        int flag=0;
        while(p!=NULL)
        {
            if(flag==0&&num==m)
            {
                t1=p;
                flag=1;
            }
            if(flag==1&&num==n)
            {
                t2=p;
                break;
            }
            num++;
            p=p->next;            //找到两个结点，用t1，t2固定
        }
        ListNode *temp1=NULL;
        ListNode *temp2=head;
        temp1=t2->next;
        int flag1=0;             //用temp1固定t2的后继节点
        while(temp2&&temp2->next!=t1)
        {
            temp2=temp2->next;
            if(temp2==t2)
               {
                flag1=1;
                break; 
               }           //用temp2固定，找到t1的前置结点。
        }
        if(flag1) temp2=NULL;
        p=t1;                                   
        stack<ListNode*> s;
        while(p!=t2)                      //将包括t1，t2的结点地址压入栈
        {
            s.push(p);
            p=p->next;
        }
        s.push(p);
        flag=1;
        if(t1==head)                                //如果t1是头节点
        {
            head=t2;
            flag=0;
        }
        if(flag)
        {
            if(temp2==NULL)
            {
            temp2=s.top();
            s.pop();
            }
            while(!s.empty())
            {
            temp2->next=s.top();
            temp2=s.top();
            s.pop();
            }
            if(temp1)
                temp2->next=temp1;
            else
                temp2->next=NULL;
            return head;
        }
        else
        {
            while(!s.empty())
            {
                t2->next=s.top();
                t2=s.top();
                s.pop();
            }
            t2->next=temp1;
            return head;
        }
        
    }
};