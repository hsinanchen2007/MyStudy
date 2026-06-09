方法一另建链表
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int nextbit=0;
        int sum=0;
        ListNode* head=new ListNode(-1);
        ListNode* it=head;
        while(l1!=NULL||l2!=NULL){
            sum=0;
            if(l1!=NULL){
                sum +=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum +=l2->val;
                l2=l2->next;  
            }
            if(nextbit){
                sum++;
                nextbit=0;
            }
            if(sum>=10) nextbit=1;
            it->next=new ListNode(sum%10);
            it=it->next;
        }  
        if(nextbit){
            it->next = new ListNode(nextbit);
        }
        return head->next;
    }
};
```
![image.png](https://pic.leetcode-cn.com/591e49920b596b73dd4cb2ae46eebe882cd433e11da127a8670165bd5a86627b-image.png)

方法二、在l1上修改
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int nextbit=0;
        ListNode* head=new ListNode(0);
        head=l1;
        while(l1!=NULL||l2!=NULL){
            if(l1->next==NULL&&l2->next!=NULL) l1->next = new ListNode(0);
            if(l2->next==NULL&&l1->next!=NULL) l2->next = new ListNode(0);
            if(nextbit){
                l1->val=l1->val+nextbit;
                nextbit=0;
            }
            if(l1->val+l2->val>=10) nextbit=1;
            l1->val=(l1->val+l2->val)%10;
            if(l1->next==NULL&&l2->next==NULL) break;
            l1=l1->next;
            l2=l2->next;  
        }  
        if(nextbit) l1->next = new ListNode(nextbit);
        return head;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8298e68452cabac7f7f100f6e061bf8c1f3448cee9a3e47f6ed61e448d126d59-image.png)
