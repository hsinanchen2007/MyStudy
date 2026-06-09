### 解题思路
此处撰写解题思路

![图片.png](https://pic.leetcode-cn.com/6ce3ba0227d5196a085ebb27dd4e1a7b2abbf091d5a6beef99072c5388346201-%E5%9B%BE%E7%89%87.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){    
    //    # p1=l1
        // # p2=l2
        struct ListNode* p=NULL;
        struct ListNode* h=NULL;
        struct ListNode* t;
        // # t=None
        int c=0;
        while(!(l1==NULL&&l2==NULL&&c==0)){
            c=((l1==NULL)?0:l1->val)+((l2==NULL)?0:l2->val)+c;
            if(p==NULL){
                p=(struct ListNode*)calloc(1,sizeof(struct ListNode));
                p->val= c%10;
                h=p;        
                // # p.next=t    
            }
            else{
                t=(struct ListNode*)calloc(1,sizeof(struct ListNode));   
                t->val= c%10;     
                p->next=t;
                p=p->next;
            }
            // if(h==NULL){
            //     h=p;
            //     }            
            c/=10;
            l1=(l1==NULL)?NULL:l1->next;
            l2=(l2==NULL)?NULL:l2->next;
        }
        return h;


}
```