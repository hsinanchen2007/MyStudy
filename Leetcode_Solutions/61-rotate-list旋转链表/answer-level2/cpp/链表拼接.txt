本质还是链表循环右移问题
```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int length=0;
        ListNode* temp=head, *res;
        //记录链表长度
        while(temp){
            length++;
            temp=temp->next;
        }
        k=k%length;
        if(k==0)return head;
        length=length-k-1;
        temp=head;
        while(length--){
            temp=temp->next;
        }   
        //返回链表头节点
        res=temp->next;
        //返回链表头节点上一个节点指向nullptr
        temp->next=nullptr;
        temp=res;
        while(temp->next){
            temp=temp->next;
        }
        //拼接链表
        temp->next=head;
        //链表
        return res;
    }
};
```
