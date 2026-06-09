用一个链表模拟队列，节点有两个指针，一个模拟队列顺序，一个模拟大小顺序
分别超越99.7% 100%
```
struct Node{
    int val;
    Node *next;
    Node *nextM;
    Node(int _val):val(_val),next(NULL),nextM(NULL){}
};
class MaxQueue {
public:
    Node* head=NULL;
    Node* tale=NULL;
    Node* max=NULL;
    MaxQueue() {
        
    }
    
    int max_value() {
        if(max==NULL)return -1;
        else return max->val;
    }
    
    void push_back(int value) {
        Node *temp=new Node(value);
        if(head==NULL){
            if(tale==NULL){
                head=temp;
                tale=temp;
                max=temp;
            }
        }
        else{
            tale->next=temp;
            tale=tale->next;
            if(value>=max->val){
                temp->nextM=max;
                max=temp;
            }
            else{
                Node* tempM=max;
                while(tempM->nextM!=NULL&&value<tempM->nextM->val)tempM=tempM->nextM;
                temp->nextM=tempM->nextM;
                tempM->nextM=temp;
            }
        }
    }
    
    int pop_front() {
        if(head==NULL)return -1;
        else{
            int res=head->val;
            if(head==tale){
                max=NULL;
                head=NULL;
                tale=NULL;
            }
            else {
                if(head==max)max=head->nextM;
                else{
                    Node* temp=max;
                    while(temp->nextM!=head)temp=temp->nextM;
                    temp->nextM=head->nextM;
                }
                head=head->next;
            }
            return res;
        }
    }
};
```
