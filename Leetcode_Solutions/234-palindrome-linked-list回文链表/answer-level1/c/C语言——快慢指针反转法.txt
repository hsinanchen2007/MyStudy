### 解题思路
参照了高赞题解。
思路:回文数有对称关系(类似二倍),所以可以设置一个快于slow指针二倍速度的fast指针,来保证slow最终位于中间位置。遍历的同时slow的前半部分进行反转。最终形成如：1<-2<-2->1->NULL的链表
特殊情况:当个数为奇数时,如1<-2<-3->2->1时,slow位于正中3时,要将slow跳至下一位进行比较。
    fast指针用于遍历一边链表;p与prior指针用于反转;p与slow指针用于判断是否为回文数。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    //快慢指针+反转
    struct ListNode *slow=head,*fast=head;
    struct ListNode *prior=NULL,*p;
    if(head==NULL||head->next==NULL) return 1;  //只有一个数,或为空时也是回文数
    //两个数及以上
    while(fast!=NULL&&fast->next!=NULL){
        p=slow;
        slow=slow->next;
        fast=fast->next->next;          //快慢指针
        //反转
        p->next=prior;prior=p;
    }                                   //while执行完后，prior为p的前继指针，p为slow的前继指针
    //奇数节点时，跳过中间节点
    if(fast!=NULL) slow=slow->next;
    //比较p,slow指针指向的值
    while(slow!=NULL){
        if(p->val!=slow->val) return 0;
        p=p->next;slow=slow->next;
    }
    return 1;
}
```