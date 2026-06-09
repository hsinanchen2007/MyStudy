```
struct ListNode *reverse(struct ListNode *head,int k,struct ListNode **temp,struct ListNode *nexthead);
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode **temp=(struct ListNode **)malloc(sizeof(struct ListNode *)*k);
    for(int i=0;i<k;i++){
        temp[i]=(struct ListNode*)malloc(sizeof(struct ListNode));
    }
    struct ListNode *nexthead=(struct ListNode *)malloc(sizeof(struct ListNode));
   
    return reverse(head,k,temp,nexthead);
}

struct ListNode *reverse(struct ListNode *head,int k,struct ListNode **temp,struct ListNode *nexthead){
    int i;
    for(i=0;i<k;i++){                     //用二级指针来表示k个l节点
        if(head!=NULL){
            temp[i]=head;
            head=head->next;    
        }
        else break; 
    }
    if(i<k){         //结束条件
        if(i==0){            
            return NULL;     
        }
        else{
            return temp[0]; 
        }           
    }
    else{
        head=temp[i-1];                     
        nexthead=head->next;                
        while(i-2>=0){                      
            temp[i-1]->next=temp[i-2];
            i--;
        }
        temp[i-1]->next=reverse(nexthead,k,temp,nexthead);
        return head;                                      
    }                                                       


```
![image.png](https://pic.leetcode-cn.com/d2874d85e20f69c03a9a7067e569f45777310fbe056a6d1189bbb112871dcf91-image.png)
