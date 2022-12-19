```
class Solution {
    //头插法插入节点
    void addAtHead(ListNode* &p,int val){
        ListNode* tmp=new ListNode(val);
        if(p!=NULL)  tmp->next=p;
        p=tmp;
    }
    //两个链表的连接，q连接到p上
    void listCombine(ListNode* &p,ListNode* &q){
        if(p==NULL)  p=q;
        else{
            ListNode* tmp=p;
            while(tmp->next!=NULL)  tmp=tmp->next;
            tmp->next=q;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)  return head;
        ListNode* list=NULL;
        ListNode* tmp=NULL;//用于保存每组节点所建立链表的临时链表
        int i=0;
        while(head!=NULL){
            i++;
            addAtHead(tmp,head->val);//头插法
            head=head->next;
            if(i==k){
                //每满k个节点后把计数i置为0，组合链表
                i=0;
                listCombine(list,tmp);
                tmp=NULL;
            }
        }
        if(i>0){
            //如果还剩下元素(剩下不满k个)则反转链表后再组合到结果中
            ListNode* last=NULL;
            while(tmp!=NULL){
                addAtHead(last,tmp->val);
                tmp=tmp->next;
            }
            listCombine(list,last);
        }
        return list;
    }
};
```
