先找最小值所在的点，再插值
```
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
            Node* N=new Node(insertVal,NULL);
            N->next=N;
            return N;
        }
        //find min
        auto cur=head->next;
        auto min=cur,max=cur;
        bool over=false,find=false;
        while(cur!=head||!over){
            if(cur==head)
                over=true;
            if(cur->val>cur->next->val){
                max=cur;
                min=cur->next;
                find=true;
                break;
            }
            cur=cur->next;
        }
        if(!find){
            Node* N=new Node(insertVal,cur->next);
            cur->next=N;
            return head;
        }
        cur=min;  
        while(cur->next!=min){
            if(cur->val<insertVal&&insertVal<cur->next->val||insertVal==cur->next->val){
                Node* N=new Node(insertVal,cur->next);
                cur->next=N;
                return head;
            }
            cur=cur->next;      
        }
        Node* N=new Node(insertVal,cur->next);
        cur->next=N;
        return head;
    }
};
```