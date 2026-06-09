![leetcode00.png](https://pic.leetcode-cn.com/de38f780853c504f85105d16e77e1194af13107767a4387f7e2a7501c8c32c66-leetcode00.png)

既然是从后往前计算，迭代就很难解题，所以选择递归
为了进行递归，需要先统一长度，短的给它补齐
补齐后再加一层，防止进位，如50+50=100，多了一位
递归
结束后判断左数第一位是不是0
```
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
    int dg(ListNode* l1,ListNode* l2,ListNode* l3)
    {
        if(l1==NULL&&l2==NULL)return 0;
        int temp=dg(l1->next,l2->next,l3->next);
        l3->val=(l1->val+l2->val+temp)%10;
        return (l1->val+l2->val+temp)/10;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1->val==0)return l2;
       else if(l2->val==0)return l1;
       int len1=0,len2=0;
       ListNode* h=l1;
        while(h!=NULL)
        {h=h->next;
         len1++;
        }
       h=l2; 
        while(h!=NULL)
        {
           h=h->next;
           len2++; 
        }
       int leng=max(len1,len2); 
        
       ListNode* dummy=new ListNode(0);
        h=dummy;
       while(leng--)
        {
          ListNode* pnew=new ListNode(0);
          h->next=pnew;
          h=h->next;
       }
       //新链表
       ListNode* mmi=new ListNode(0);
       ListNode* nni=new ListNode(0); 
       if(len1!=len2)
       {
           h=mmi;
           int slen=abs(len1-len2);
        while(slen--)
        {
           ListNode* temp=new ListNode(0);
           h->next=temp;
           h=h->next; 
        }
        h->next=len1>len2?l2:l1;
        
        nni->next=len1>len2?l1:l2;   
       }
        else
        {
           mmi->next=l1;
           nni->next=l2;
        }
       int x=dg(mmi,nni,dummy);
       if(dummy->val==0)return dummy->next;
        else return dummy;
        
    }
};
```
解决
第一次写题解，感觉还行才敢写