### 解题思路
首先解决两边相加的问题，再解决只剩下一边的情况

### 代码

```cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;
        int flag;//0不进位,1进位

        int val;
        val=p->val+q->val;
        if(val>=10){
            val-=10;
            flag=1;
        }
        else{
            flag=0;
        }
        ListNode* tmp = new ListNode(val);
        ListNode* l3=tmp;
        ListNode* k=tmp;


        p=p->next;
        q=q->next;       
        while(p!=NULL&q!=NULL){
            int val;
            val=flag+p->val+q->val;
            if(val>=10){
                val-=10;
                flag=1;
            }
            else{
                flag=0;
            }
            ListNode* tmp = new ListNode(val);
            k->next=tmp;
            k=tmp;
            p=p->next;
            q=q->next;
        }
        if(p!=NULL){
            while(p!=NULL){
                int val;
                val=flag+p->val;
                if(val>=10){
                    flag=1;
                    val-=10;
                }
                else{
                    flag=0;
                }
                ListNode* tmp = new ListNode(val);
                k->next=tmp;
                k=tmp;
                p=p->next;
            }
        }
        else if(q!=NULL){
            while(q!=NULL){
                val=flag+q->val;
                if(val>=10){
                    flag=1;
                    val-=10;
                }
                else{
                    flag=0;
                }
                ListNode* tmp = new ListNode(val);
                k->next=tmp;
                k=tmp;
                q=q->next;
            }
        }
        if(flag==1){
            ListNode* tmp=new ListNode(1);
            k->next=tmp;
            k=tmp;
        }
        return l3;
    }
};
```