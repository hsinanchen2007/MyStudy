/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      int length=0,lengthk=0;
      ListNode *p=head,*slow,*fast;
      if(k==0||head==NULL)  return head;
      while(p){
          length++;
          p=p->next;
      }
     lengthk=k%length;
    if(lengthk==0) return head;
    slow=head;
    fast=head;
    while(lengthk){
        fast=fast->next;
        lengthk--;
    }
    while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=head;
    head=slow->next;
    slow->next=NULL;
    return head;
    }
};
/*
首先，我个人的思路是利用快慢指针进行定位，然后再进行拼接，我们首先思考K的含义有三种情况
1.K为链表长度发的整数倍，说明链表长度旋转了几个周期，可以推导出直接返回head指针
2.当K的值大于链表长度的时候，说明链表旋转了一个周期以上，我们对K进行链表长度的模运算，得出的结果就是需要旋转的长度
3.当K小于链表长度时，正常操作即可
接下来我们利用快慢指针来定位需要截取的位置即可，先让快指针后移动K位然后在快慢指针一起移动即可。
*/