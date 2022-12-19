### 解题思路
**基本模仿官方那个java写法**

1.创建一个空链表l3来存储结果，用p q cur指代位置。
2.依次遍历两个链表，取val相加，加上flag（进位标志位）。
3.在l3依次创建节点
4.最后判断是否还有进位，有进位再补充一个节点
5.注意最后返回第一个有数值的节点,用l3->next

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
        ListNode *l3=new ListNode(-1);
        ListNode *p=l1,*q=l2,*cur=l3;
        int flag=0;//进位标志
        while(p!=NULL||q!=NULL)
        {
           int x=(p!=NULL)?p->val:0; 
           int y=(q!=NULL)?q->val:0; 
           int sum=x+y+flag;
           flag=sum/10;
           cur->next=new ListNode(sum%10);
           cur=cur->next;
           if(p!=NULL) p=p->next;
           if(q!=NULL) q=q->next;
        }
        if(flag==1)
        {
            cur->next=new ListNode(flag); 
        }
        return l3->next;
    }
};
```