每一次交换必须要知道三个节点：交换节点1、交换节点2和交换节点1之前的一个节点。（注意：第一次交换的节点1没有上一节点，就自己新建一个，就是给这条链上创建一个新的首节点）
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp=new ListNode(-1);
        temp->next=head;
        ListNode* left=temp;
        ListNode* temp1=head;
        ListNode* temp2=temp1->next;
        while(temp2!=NULL){
           temp1->next=temp2->next;
           left->next=temp2;
           temp2->next=temp1;
           left=temp1;
           temp1=temp1->next;
           if(temp1==NULL) break;
           temp2=temp1->next;
        }
        return temp->next;
    }
};
```
