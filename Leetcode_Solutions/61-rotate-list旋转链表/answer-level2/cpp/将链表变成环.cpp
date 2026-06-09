//代码有点复杂 但是可以运行
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)     return NULL;
        int n=1,num;
        ListNode *p, *q;
        p=head;
        while(p->next!=NULL){
                   p=p->next;//此时是最后一个结点
                    n++;//统计一共有多少个结点
        }
        //先把这个链表连接成一个环形链表
        p->next=head;
        if(k<n)
                num=n-k;
        else //这是应对那k值比结点总数大的情况  
           num=n-(k-n)%n;
        for(int i=1;i<num;i++){
            head=head->next;
        }
        q=head->next;
        head->next=NULL;
            return q;
    }
};
```
