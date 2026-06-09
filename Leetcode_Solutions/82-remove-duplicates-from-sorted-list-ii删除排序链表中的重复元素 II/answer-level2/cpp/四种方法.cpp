方法一 找到所有相同数后再将出现相同数的前一个数连接到相同数后第一个不同的数
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* dummy= new ListNode(-1),*p=dummy,*st=NULL;
        dummy->next=head;
        int count=0;
        while(p->next!=NULL&&p->next->next!=NULL){   
            if(p->next->val==p->next->next->val){
                if(count==0) st=p;
                count=1;
                p=p->next;
            }
            else if(p->next->val!=p->next->next->val&&count){
                count=0;
                st->next=p->next->next;
                p=st;
            } 
            else p=p->next;
        }
        if(p->next->next==NULL&&count) st->next=NULL;
        return dummy->next;
    }
};
```
方法二 找到一次连接一次 eg 1->2->3->3->3->4->5, 当找到相同数时，循环一次后1->2->3->3->4->5
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy= new ListNode(-1),*p=dummy;
        dummy->next=head;
        int count=0;
        while(p->next!=NULL&&p->next->next!=NULL){
            if(p->next->val!=p->next->next->val&&count){
                p->next=p->next->next;
                count=0;
            }
            else if(p->next->val==p->next->next->val){
                count=1;
                p->next=p->next->next;
            }
            else p=p->next;
        }
        if(count==1) p->next=p->next->next;
        return dummy->next;
    }
};
```
方法三 快慢指针
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1),*slow = dummy,*fast = head;
        dummy->next = head;
        while(fast!=NULL&&fast->next!=NULL){ //快指针用于查找相同元素
            if(fast->val!=fast->next->val) {                  
                if(slow->next == fast) slow = fast; //快指针先前没查找到相同数
                else slow->next = fast->next; //先前查找到相同数，将出现相同数的前一个数连接到相同数后第一个不同数 
            }
            fast = fast->next;
        }
        if(slow->next != fast) slow->next = fast->next; // 针对类似[1,1]的情况
        return dummy->next;
    }
};
```
方法四 递归
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)  return head;
        if (head->next != NULL && head->val == head->next->val) { //找相同数
            while (head->next != NULL && head->val == head->next->val)  head = head->next;  //忽略所有相同数
            return deleteDuplicates(head->next); //从下一个不同数再开始递归
        }
        else head->next = deleteDuplicates(head->next);
        return head;   
    }
};
```



