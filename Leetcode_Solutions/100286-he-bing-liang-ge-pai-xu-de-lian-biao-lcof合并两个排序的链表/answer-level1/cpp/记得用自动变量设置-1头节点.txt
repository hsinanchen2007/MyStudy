 如果写成auto p=new ListNode(-1)的话，程序运行完这个变量就丢了，
虽然很多题目自己都不是很规范，但是作为答题人这方面的细节能够体现出
内存控制的良好习惯。设置成自动变量时，直接返回nHead.next后，nhead
自动变量自己释放掉了。

``` C++ []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #define next(p) (p)=(p)->next;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode nhead(-1);
        auto p=&nhead;
        while(l1&&l2){
            //cout<<l1->val<<" "<<l2->val<<endl;
            if(l1->val>l2->val){
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }else{
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
        }
        if(l1) p->next=l1;
        if(l2) p->next=l2;
        return nhead.next;
    }
};
```