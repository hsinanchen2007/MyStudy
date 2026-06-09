### 解题思路
此处撰写解题思路

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){    /*若链表大小为1，直接删除头结点*/
            delete head;
            head=NULL;
            return head;
        }
        ListNode *q=head;
        int cnt=0;  /*计算链表大小*/
        while(q){
            q=q->next;
            ++cnt;
        }
        ListNode *p=head;
        ListNode *s;
        int m=cnt-n;    /*倒数转化成正数第几个*/
        if(m==0){   /*如果是第一个，则删除头结点*/
            ListNode *r=head;
            head=head->next;
            delete r;
            r=NULL;
            return head;
        }
        int j=1;
        while(j<m&&p){
            p=p->next;
            ++j;
        }
        s=p->next;  /*s指向倒数第n个节点*/
        p->next=s->next;    /*删除倒数第n个节点*/
        delete s;
        s=NULL;
        return head;  
    }
};
```